# strcpy 和 memcpy 的区别(待完善测试实例)

## strcpy

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

## memcpy

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