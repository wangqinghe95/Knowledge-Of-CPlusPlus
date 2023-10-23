# strcpy/strncpy/memcpy 

## strcpy
1. 描述
    + 将一个字符串复制到另一个字符串中
2. 实现

```
char *myStrcpy(char* dest, const char* src){
    if ((NULL == dest) || (NULL == src)){
        return NULL;
    }

    char *strDest = dest;
    const char *strSrc = src;
    while ((*dest++ = *strSrc++) != '\0');
    return strDest;    
}
```


## strncpy
1. 描述
    + 将一个字符串的前 count 字符复制到另一个字符串中
2. 实现

```
char* strncpy(char* dest, const char* source, size_t count){
    if (NULL == dest || NULL == source || count <= 0){
        return NULL;
    }

    char *start = dest;
    while (count && (*dest++ = *source++)){
        count--;
    }

    if (count){
        while(--count){
            *dest ++ = '\0';
        }
    }

    return (start);
}
```

## memcpy
1. 描述
    + 将一个内存中的前 size 字符复制到另一个字符串中
2. 实现

```
void *myMemcpy(void *dest, const void *src, size_t size){
    if(NULL == dest || NULL == src){
        return NULL;
    }

    char *pDest = NULL;
    char *pSrc = NULL;

    if ((src < dest) && ((char*)src + size > (char*)dest)){
        pDest = (char *)dest + size - 1;
        pSrc = (char *)src + size - 1;
        while(size--){
            *pDest-- = *pSrc--;
        }
    }
    else{
        pSrc = (char *)src;
        pDest = (char *)dest;
        while (size--)
        {
            *pDest++ = *pSrc;
        }
    }
    
    return dest;
}
```

