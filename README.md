#### 运行本项目需要的环境为：

##### Ø 系统：

Ubuntu 18.04 LTS

##### Ø 处理器：

Intel® Core™ i7-10750H CPU @ 2.60GHz × 4

##### Ø 操作系统位数：

64-bit

##### Ø Python版本：

Python 3.11.2或以上

##### 需要安装python库为：

###### l logging=0.5.1.2

###### l antlr=4.8

##### Ø Gcc版本：

gcc version 12.2.0或以上

##### Ø Antlr版本：

antlr-4.8-complete.jar

##### Ø NASM版本：

NASM version 2.13.02

#### 运行方法：

在项目根目录下运行main.py go文件目录，可以看到根目录下会出现3code.txt和out.asm两个文件，就是翻译的结果。（这一步可以在Windows下运行）。

因为我们生成的是linux下的32位的可执行文件，所以要把生成的out.asm文件到linux下进行汇编和链接：

##### 汇编：

在linux下执行nasm -f elf32 -o out/out.o out/out.asm

##### 链接：

为了让我们的程序可以输出，我们要和自己写的myprint函数进行链接，在linux下执行ld -m elf_i386 -o out/out.bin out/out.o out/print.o

##### 运行：

找到你的目录下生成的可执行文件，直接运行即可./out/out.bin