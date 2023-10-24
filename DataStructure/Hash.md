# Hash

## 一致性 Hash
+ 概念
    - 一种特殊的 hash 算法，用于解决分布式系统数据分区问题
+ 应用场景
    - 在分布式缓存服务中，会经常需要对服务节点进行添加和删除操作。在这过程中，希望能尽量减少数据-节点之间的映射关系更新
    - Hash 取模算法作为理由策略会造成大量的请求无法命中，而导致缓存数据被重新加载。
    - 基于以上原因，出现一致性 Hash 算法
+ 描述
    - 一致性 Hash 会将整个 Hash 值空间按照顺时针方向组织成一个圆环，成为 Hash 环。
    - 然后各个服务器使用 Hash 函数进行 Hash，从而确定每个机器在 Hash 环上的位置。
    - 最后使用算法定位数据访问到相应的服务器：
        - 将数据 key 使用相同的函数 Hash 计算出 Hash 值，并确定此数据在环上的位置
        - 从此位置沿环顺时针寻找，遇到的第一台服务器就是其应该定位到的服务器
+ 影响分析
    + 结果添加只会影响新增节点和之间的一个节点的数据。
    + 节点删除只会影响删除节点和之前一个节点的数据。

+ 代码
```
// ConsistentHash.hpp
# ifndef CONSISTENT_HASH_HPP_
# define CONSISTENT_HASH_HPP_

#include <map>
#include <set>
#include <string>

class ConsistentHash
{
private:
    std::map<uint32_t, std::string> m_serverNodes;
    std::set<std::string> m_physicalNodes;
    int m_virtualNodeNum;
public:
    ConsistentHash(int virtualNodeNum) : m_virtualNodeNum(virtualNodeNum) {
        m_physicalNodes.insert(std::string("192.168.1.101"));
        m_physicalNodes.insert(std::string("192.168.1.102"));
        m_physicalNodes.insert(std::string("192.168.1.103"));
        m_physicalNodes.insert(std::string("192.168.1.104"));
    }

    ~ConsistentHash() {
        m_serverNodes.clear();
    }
public:
    static uint32_t FNVHash(std::string key);
    void Initialize();
    void AddNewPhysicalNode(const std::string& nodeIP);
    void DeletePhysicalNode(const std::string& nodeIP);
    std::string GetServerIndex(const std::string& key);
    void StatisticPref(std::string& label, int left, int right);

};

# endif
// ConsistentHash.cpp
#include "ConsistentHash.hpp"

#include <sstream>
#include <iostream>

// Hash algorithm of Fowler-Noll-Vo of 32 bit
// https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function
uint32_t ConsistentHash::FNVHash(std::string key)
{
    const int p = 16777619;
    uint32_t hash = 2166136261;
    for(int idx = 0; idx < key.size(); ++idx) {
        hash = (hash ^ key[idx]) * p;
    }

    hash += hash << 13;
    hash ^= hash >> 7;
    hash += hash << 3;
    hash ^= hash >> 17;
    hash += hash << 5;
    if(hash < 0) {
        hash = -hash;
    }

    return hash;
}
void ConsistentHash::Initialize()
{
    for(auto& ip : m_physicalNodes) {
        for(int j = 0; j < m_virtualNodeNum; ++j) {
            std::stringstream nodeKey;
            nodeKey << ip << '#' << j;
            uint32_t partition = FNVHash(nodeKey.str());
            m_serverNodes.insert({partition, ip});
        }
    }
}

// insert a physical node
void ConsistentHash::AddNewPhysicalNode(const std::string& nodeIP)
{
    for(int j = 0; j < m_virtualNodeNum; ++j) {
        std::stringstream nodeKey;
        nodeKey << nodeIP << '#' << j;
        uint32_t partition = FNVHash(nodeKey.str());
        m_serverNodes.insert({partition, nodeIP});
    }
}
void ConsistentHash::DeletePhysicalNode(const std::string& nodeIP)
{
    for(int j = 0; j < m_virtualNodeNum; ++j) {
        std::stringstream nodeKey;
        nodeKey << nodeIP << '#' << j;
        uint32_t partition = FNVHash(nodeKey.str());
        auto it = m_serverNodes.find(partition);

        if(it != m_serverNodes.end()) {
            m_serverNodes.erase(it);
        }
    }
}
std::string ConsistentHash::GetServerIndex(const std::string& key)
{
    uint32_t partition = FNVHash(key);
    auto it = m_serverNodes.lower_bound(partition);

    // find a virtual node with more and equal with parition by clockwise along the ring
    if(it == m_serverNodes.end()) {
        if(m_serverNodes.empty()) {
            std::cout << "No available node" << std::endl;
        }

        return m_serverNodes.begin()->second;
    }

    return it->second;
}

// find a situable stored node for data within the range of [objmin, objmax]
void ConsistentHash::StatisticPref(std::string& label, int left, int right)
{
    std::map<std::string, int> cnt;
    for(int i = left; i <= right; i++) {
        std::string nodeIP = GetServerIndex(std::to_string(i));
        cnt[nodeIP]++;
    }

    int total = right - left + 1;
    std::cout << "======= " << label << " ========" << std::endl;
    for(auto& p : cnt) {
        std::cout << "nodeIP: " << p.first << " rate: " << 100 * p.second / (total * 1.0) <<"%" << std::endl;
    }
}
// test.cpp
#include "ConsistentHash.hpp"
#include <iostream>

int main()
{
    ConsistentHash ch(1);
    ch.Initialize();

    std::string label("Initialization");
    ch.StatisticPref(label, 0, 65536);

    ConsistentHash ch2(32);
    ch2.Initialize();
    std::string label2("Initialization");
    ch2.StatisticPref(label2, 0, 65536);

    // std::cin.get();


    ConsistentHash ch3(32);
    ch3.Initialize();
    std::string label3 = "Delete Physical Node";
    std::string ip3 = "192.168.1.101";
    ch3.DeletePhysicalNode(ip3);
    ch3.StatisticPref(label3, 0 ,65536);

    ConsistentHash ch4(32);
    ch4.Initialize();
    std::string label4 = "Add Physical Node";
    std::string ip4 = "192.168.1.108";
    ch4.AddNewPhysicalNode(ip4);
    ch4.StatisticPref(label4, 0 ,65536);

    return 0;
}
```

+ [ConsistentHash 参考资料](https://zhuanlan.zhihu.com/p/379724672)
