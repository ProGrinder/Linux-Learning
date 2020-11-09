# 地址空间


## 地址中的ELF

- 栈帧    (本地变量)
- Data 数据段   (全局变量和静态变量)
- Text 代码段



## goto

打乱程序正常运行流程

- 函数内部 
  - goto + label
- 函数间跳转 （需要有<setjmp.h>头文件）
  - setjmp	  =>设置跳转点
  - longjmp   =>跳转