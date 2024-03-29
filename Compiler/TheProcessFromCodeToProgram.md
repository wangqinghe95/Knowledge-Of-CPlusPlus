# C++ 从代码到可执行程序经历了什么
1. 预编译：主要是处理源代码文件以"#"开头的预编译指令，处理规则如下：
    + 删除所有的 #define，展开所有的宏定义；
    + 处理所有的条件预编译指令，如"#if","#endif","#elif#,"#else"；
    + 处理 "#include" 预编译指令，把文件内容替换到相应的位置，该过程是递归进行的，文件中包含其他文件；
    + 删除所有注释， "//" 和 "/**/"
    + 保留所有的 #pragma 编译器指令，编译器需要用到他们，如:#pragma once 是为了防止有文件被重复引用；
    + 添加行号和文件标识，便于编译时编译器产生调试用的行号信息，和编译产生编译错误新或是警告时能够显示行号
2. 编译：把预编译之后生成的 xxx.i 或者 xxx.ii 文件进行一些列词法分析，语法分析，语义分析及优化，生成相应的汇编代码文件；
    + 词法分析：利用类似于 "有限状态机" 的算法，将源代码输入到扫描机中，将其中字符序列分割成一系列的记号；
    + 语法分析：语法分析器只是完成了对表达式语句层面的分析，语义分析其则对表达式是否有意义进行判断，其分析的语义是静态语义，在编译器能分析的语义，相对应的动态语义是运行期才能确定的语义；
    + 优化：源代码级别的一个优化过程；
    + 目标代码生成：由代码生成器将中间代码转换成目标机器代码，生成一系列的代码序列--汇编语言表示；
    + 目标代码优化：目标代码优化器对上述的目标机器代码进行优化：寻找合适的寻址方式、使用位移来代替乘法运算，删除多余指令等；
3. 汇编：将汇编代码转变成机器可以执行的指令（机器码文件）。汇编器的汇编过程相对于编译器更见，没有复杂的语法，也没有语义，更不需要做指令优化，只是根据汇编指令和机器指令的对照表一一翻译，汇编过程由汇编器as完成，经汇编之后，产生目标文件（与可执行文件格式几乎一样）xxx.o，xxx.obj（windows下）
4. 链接：将不同的源文件产生的目标文件进行链接，从而形成一个可以执行的程序。链接分为静态链接和动态链接：
    - 静态链接：函数和数据被编译进一个二进制文件，在使用静态库的情况下，在编译链接可执行文件中，链接器从库中复制这些函数和数据把它们和应用程序的其他模块组合起来创建最终可执行文件；因为每个可执行文件对所有需要的目标文件都要有一个备份，所以如果多个程序对同一个目标文件都有依赖，会出现同一个目标文件在内存中存在多个副本；每当函数库代码修改后，都需要重新编译链接形成可执行程序；但是优点是在可执行程序中已经具备了所有可执行程序所需要的东西，执行时候运行速度很快；
    - 动态链接：动态链接的基本思想就是把程序按照模块拆分成各个相对独立的部分，在程序运行时才将它们链接在一起形成一个完整的程序，而不是像静态链接那样把所有的程序模块都链接成一个独立可执行的文件；即使每个程序都依赖同一个库，但是该库在内存中只有一份，程序执行时共享同一份副本；更新时只需要替换掉原来的目标文件，新版的目标文件会自动加载到内存并且链接起来，程序就完成了升级。缺点是动态库的链接时机推迟到了程序运行时，每次执行程序都会进行链接，所以执行速度没有静态链接方式来的快；

# hello.c 程序的编译过程
1. 预处理阶段：与处理器处理源代码中以 # 号开头的预处理命令，如 #include, #define， 即生成一个 .i 文件；
2. 编译阶段：编译器将预处理后的文件翻译成汇编文件，即生成一个 .s 文件；
3. 汇编阶段：汇编器将汇编文件翻译成机器语言，即生成一个 .o 文件；
4. 链接阶段：链接器将多个目标文件( .o 文件)和库文件( .lib 和 .a 文件)合成一个可执行文件，即生成一个 .exe 或者 .out 文件；