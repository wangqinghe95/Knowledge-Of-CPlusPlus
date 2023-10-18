# 动态库
+ 目标文件是经过编译但是还未链接的二进制机器码文件。
+ 动态库就是一份可以在程序运行时加载，并且允许多个程序共享使用的目标文件。

## 动态库编译
+ `g++ [source_file] -fPIC -shared -o lib[library_name].so`

## 动态库链接
+ `g++ [main.cpp] -o [program_name] -L [path_library_name] -l[library_name]`

## 动态库检查
+ ldd [program_name]
    - 查看执行文件是否已经正确链接到动态库

## 动态库寻找路径
+ 程序运行时会以以下顺序的路径去寻找需要加载的动态库
    1. 编译时编译命令中指定的动态库搜索路径
        - `-Wl,-rpath,[path]`
    2. 环境变量 LD_LIBRARY_PATH 指定的动态库搜索路径
        - `export LD_LIBRARY_PATH=[path]`
        - 临时生效
    3. 配置文件 /etc.ld.so.conf 文件中记录的动态库路径
    4. 默认的动态库搜索路径
        - /lib, /usr/lib

## 动态库优缺点
### 优点：
1. 动态库可以共享，较少可执行程序的大小
2. 可执行代码修改时，动态库无需重新编译
### 缺点
1. 运行期间加载，减少代码的执行速度
2. 增加程序的依赖项