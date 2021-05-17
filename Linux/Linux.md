# grep、awk、sed
## grep
+ grep:global search regular expression and print out the line，全面搜索正则表达式并把行打印出来，是一个文本搜索工具，能够使用正则表达式搜索文本，并把匹配的行打印出来。用于过滤/搜索特点字符。
+ 格式：
    grep [options] 'pattern' filename

## awk
+ 作用：在文件或者字符串中基于指定规则浏览和抽取信息。awk抽取信息后才会进行其他文本操作。完整的awk脚本通常是用于格式化文本文件中的信息。
+ 格式：
    + awk '{pattern + action}' {filenames}
    + pattern 表示在数据中查找的内容，花括号不需要在程序中始终出现，但是它们用于根据特定的模式对一系列指令进行分组；

## sed
+ 介绍：stream editor，文本流编辑
+ 工作方式：
    1. 每次从文件中读取一行内容；
    2. 根据提供的规则命令匹配并修改数据。sed默认不会直接修改源文件数据，而是会把数据拷贝到缓冲区，修改也只是会对缓冲区的数据进行修改；
    3. 将执行结果输出到屏幕上；
    4. 处理完当前行数据后，才会继续读取下一行数据，并重复上述步骤，直到文件结束；
+ 格式：
    sed [option] 'sed command' filename

# linux 下动态库搜索顺序
1. 编译目标代码时指定的动态库搜索路径；
2. 环境变量 LD_LIBRARY_PATH 指定的动态库搜索路径；
3. 配置文件 /etc.ld.so.conf 中指定的动态库搜索枯井；
4. 默认的动态库搜索路径 /lib
5. 默认的动态库搜索路径 /usr/lib

与动态链接库相关的命令：
1. ld 是 gcc 的链接程序；
2. ldd 是查看可执行文件中所依赖的库的程序；
3. ldconfig 是用来更新文件 /etc/ld.so.conf 的修改生效的；
4. nm 是用来查看 .so 库的函数名字，标记的 T 就是动态库里面生成的名字

---

# gdb 调试

# vim 搜索、替换