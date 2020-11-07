* to compile you can simply run: gcc *.c
* tested on Linux, but should work on Windows and MacOS
* cmd line usage: "./a.out path/to/program/dir/"
* does not support binary/hex numbers
* does not translate VM or XVM instructions into XHAL

for my return ASM function I wasn't able to get it working so I took the ASM
code from this github repo:
https://github.com/kronosapiens/nand2tetris/blob/master/projects/07/VMtranslator.py 
