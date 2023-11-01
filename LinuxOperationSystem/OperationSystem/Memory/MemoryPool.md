# 内存池

+ 概念
    - 内存池是一种内存分配方式，用于减少内存碎片和减少程序运行时间。
	- 一次性向操作系统申请一大堆内存，在此之上构建需要的对象，用完之后统一返还给操作系统。
+ 好处
	这样做最大的好处是避免了频繁的 new/delete 开销和带来的内存碎片问题。

+ 思路
    - 在使用内存池技术时，程序预先申请分配一定数量、大小相等的内存块留作备用
    - 当有新的内存需求时，从内存池中分出一部分内存块；若内存块不够再继续申请新的内存
    - 通过以上操作，可以避免频繁地向操作系统申请内存，从而提高程序运行效率
	
## 实现
1. 重载 new
2. 创建内存节点
3. 创建内存池
4. 管理内存池

### 内存池节点
1. 所属池子
    + 后续在内存池管理中可以直接调用申请的内存和释放内存
2. 下一个节点
    + 使用链表，将所有的内存块串联起来
3. 节点是否被使用
    + 保证每次使用前，该节点没有被使用
4. 是否属于内存池
    + 因为一般内存池维护的空间不会太大，但是用户申请了特别大的内存时，就不能使用内存池中的内存块。走正常的申请流程，释放也是

### 内存池设计
1. 内存块首地址
    + 第一块内存，方便寻找后面的内存块
2. 内存块头
    + 内存池节点
3. 内存块大小
    + 每个节点大小
4. 节点数
    + 有多少个内存节点

### 内存释放
1. 释放内存后，将使用过的内存置为 false，然后指向头部，将头部作为下一个节点

### 内存池管理
1. 内存池创建后，根据节点大小和个数，创建相应的内存池
2. 内存池管理主要是根据不同的需求，创建不同的内存池，以达到管理的目的
3. 数组映射
    + 不同的范围内，选择不同的内存池

## 代码
```
// MemoryPool.hpp
# ifndef _MEMORYPOOL_HPP_
# define _MEMORYPOOL_HPP_

#include <iostream>
#include <mutex>

const int MAX_MEMORY_SIZE = 256;

class MemoryPool;

struct MemoryBlock
{
    bool m_bUsed;
    bool m_bBelong;
    MemoryBlock* m_pMemBlockNext;
    MemoryPool* m_pMemPool;
};

class MemoryPool
{
public:
    MemoryPool(size_t nSize = 128, size_t nBlock = 10);

    virtual ~MemoryPool();

    void* allocMemory(size_t nSize);
    void initMemory();
    void freeMemory(void* p);

public:
    char* m_pBuffer;
    size_t m_nSize;
    size_t m_nBlock;
    MemoryBlock* m_pMemBlockHeader;

    std::mutex m_mutex;
};

template<size_t size, size_t nblock>
class MemoryPoolor : public MemoryPool
{
public:
    // MemoryPoolor() : m_nSize(size), m_nBlock(nblock){}
    MemoryPoolor(){
        m_nSize = size;
        m_nBlock = nblock;
    }
};

class ManagerPool
{
public:
    static ManagerPool& Instance()
    {
        static ManagerPool m_memPool;
        return m_memPool;
    }

    void* allocMemory(size_t size);
    void freeMemory(void *p);
private:
    ManagerPool();
    ~ManagerPool(){}

    void initArray(int nBegin, int nEnd, MemoryPool* pMemPool);

private:
    MemoryPoolor<128,1000> m_memory128;
    MemoryPoolor<256,1000> m_memory256;

    MemoryPool* m_arrAlloc[MAX_MEMORY_SIZE + 1];
};

#endif

// MemoryPool.cpp
#include "MemoryPool.hpp"

MemoryPool::MemoryPool(size_t nSize, size_t nBlock)  
            : m_pBuffer(NULL)
            , m_nSize(nSize)
            , m_nBlock(nBlock)
            , m_pMemBlockHeader(nullptr)
{

}

MemoryPool::~MemoryPool()
{
    if(m_pBuffer != nullptr) {
        free(m_pBuffer);
    }
}

void* MemoryPool::allocMemory(size_t nSize)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    if(m_pBuffer == nullptr) {
        initMemory();
    }

    MemoryBlock* pRes = nullptr;
    if(m_pBuffer == nullptr) {
        pRes = (MemoryBlock*)malloc(nSize + sizeof(MemoryBlock));
        pRes->m_bBelong = false;
        pRes->m_bUsed = false;
        pRes->m_pMemBlockNext = nullptr;
        pRes->m_pMemBlockNext = nullptr;
    }
    else {
        pRes = m_pMemBlockHeader;
        m_pMemBlockHeader = m_pMemBlockHeader->m_pMemBlockNext;
        pRes->m_bUsed = true;
    }

    return ((char*)pRes + sizeof(MemoryBlock));
}

void MemoryPool::freeMemory(void* p)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    // MemoryBlock* pBlock = (MemoryBlock*)((char*)p - sizeof(MemoryBlock));
    MemoryBlock* pBlock = ((MemoryBlock*)p - sizeof(MemoryBlock));
    if(pBlock->m_bBelong) {
        pBlock->m_bUsed = false;
        pBlock->m_pMemBlockNext = m_pMemBlockHeader;
        pBlock = m_pMemBlockHeader;
    }
    else {
        free(pBlock);
    }
}

void MemoryPool::initMemory()
{
    if(m_pBuffer != nullptr) {
        return;
    }

    size_t nPoolSize = m_nSize + sizeof(MemoryBlock);
    size_t nBufferSize = nPoolSize * m_nBlock;

    m_pBuffer = (char*)malloc(nBufferSize);

    m_pMemBlockHeader = (MemoryBlock*)m_pBuffer;
    m_pMemBlockHeader->m_bUsed = false;
    m_pMemBlockHeader->m_bBelong = true;
    m_pMemBlockHeader->m_pMemPool = this;

    MemoryBlock* tmp1 = m_pMemBlockHeader;
    for(size_t i = 1; i < m_nBlock; ++i) {
        MemoryBlock* tmp2 = (MemoryBlock*)(m_pBuffer + i*nPoolSize);
        tmp2->m_bUsed = false;
        tmp2->m_pMemBlockNext = NULL;
        tmp2->m_bBelong = true;
        m_pMemBlockHeader->m_pMemPool = this;
        tmp1->m_pMemBlockNext = tmp2;
        tmp1 = tmp2;
    }
}

ManagerPool::ManagerPool()
{
    initArray(0, 128, &m_memory128);
    initArray(129, 256, &m_memory256);
}

void* ManagerPool::allocMemory(size_t size)
{
    if(size < MAX_MEMORY_SIZE) {
        return m_arrAlloc[size]->allocMemory(size);
    }
    else {
        MemoryBlock* pRes = (MemoryBlock*)malloc(size + sizeof(MemoryBlock));
        pRes->m_bBelong = false;
        pRes->m_bUsed = true;
        pRes->m_pMemPool = nullptr;
        pRes->m_pMemBlockNext = nullptr;

        return ((char*)pRes + sizeof(MemoryBlock));
    }
}
void ManagerPool::freeMemory(void *p)
{
    MemoryBlock* pBlock = (MemoryBlock*)((char*)p - sizeof(MemoryBlock));
    if(pBlock->m_bBelong) {
        pBlock->m_pMemPool->freeMemory(p);
    }
    else {
        free(pBlock);
    }
}
void ManagerPool::initArray(int nBegin, int nEnd, MemoryPool* pMemPool)
{
    for(int i = nBegin; i <= nEnd; ++i) {
        m_arrAlloc[i] = pMemPool;
    }
}


// OpeartorMem.hpp
#ifndef OPERATOR_MEM_HPP_
#define OPERATOR_MEM_HPP_

#include "MemoryPool.hpp"

void* operator new(size_t size)
{
    return ManagerPool::Instance().allocMemory(size);
}

void operator delete(void* p)
{
    return ManagerPool::Instance().freeMemory(p);
}

void* operator new[](size_t size)
{
    return ManagerPool::Instance().allocMemory(size);
}

void operator delete[](void* p)
{
    return ManagerPool::Instance().freeMemory(p);
}

#endif

// testMain.cpp
#include "OperatorMem.hpp"

using namespace std;

int main()
{
    char*p = new char[128];
    delete[] p;
    return 0;
}
```

+ [内存池参考网站](https://zhuanlan.zhihu.com/p/139835423)