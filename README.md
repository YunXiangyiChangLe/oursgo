#### 运行本项目需要的环境为：

##### Ø 系统：

Ubuntu 22.04 LTS

##### Ø 处理器：

Intel® Core™ i7-10750H CPU @ 2.60GHz × 4

##### Ø 操作系统位数：

64-bit

##### Ø Python版本：

Python 3.11.2或以上

##### Ø Gcc版本：

gcc version 12.2.0或以上

##### Ø Antlr版本：

antlr-4.8-complete.jar

##### Ø NASM版本：

NASM version 2.13.02

##### Ø java版本：

Ø java version"1.8.0_361"

#### 运行方法：

在项目根目录下运行`main.py go文件目录`，可以看到根目录下会出现3code.txt和out.asm两个文件，就是翻译的结果。

3code.txt是生成的三地址文件。

out.asm是生成的汇编文件。

##### 汇编：

在linux下执行`nasm -f elf32 -o out/out.o out/out.asm`

##### 链接：

为了让我们的程序可以输出，我们要和自己写的myprint函数进行链接，在linux下执行`ld -m elf_i386 -o out/out.bin out/out.o out/print.o`

##### 运行：

找到目录下生成的可执行文件，直接运行即可`./out/out.bin`