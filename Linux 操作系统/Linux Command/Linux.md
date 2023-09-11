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

# 常用命令
1. netstat：显示TCP、IP、UDP、ICMP 协议相关的统计数量
2. tcpdump：截取网络分组，并输出分组内容的工具。
