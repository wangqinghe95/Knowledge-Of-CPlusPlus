# const char* 、 char * 和 string 相互转换

1. string 转 const char*
```
string s = "abc";   //const char* => string
const char *s = s.c_str();  //string 转成 char* 直接给 const char* 赋值
```

2. const char* 转 string，直接赋值即可
```
const char* s = "abc";
string str(s);  //直接使用const char* 字符串初始化 string 类型
```

3. string 转 char*
```
string s = "abc";
char *c;
const int len = s.lengtj();
c = new char[len+1];
strcpy(c, s.c_str());
```

4. char* 转 string
```
char *c = "abc";
string s(c);
```

5. const char* 转 char*
```
const char* cpc = "abc";
char pc = new char[stelen(cpc) + 1];
strcpy(pc, cpc);
```

6. char* 转 const char*，直接赋值
```
char *pc = "abc";
const char * cpc = pc;
```

总结：
    char* 转 const char* 直接赋值
          转 string 初始化、赋值皆可
    const char* 转 char* 需要拷贝过去
                转 string 初始化、赋值皆可
