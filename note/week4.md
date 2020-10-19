



不同的文件系统类型索引内容存在差异





Virtural File System(VFS)



EXTZ   NTFS   ...

采用标准的Unix系统调用读写位于不同物理介质上的不同文件系统,即为各类文件系统提供了一个统一的操作界面和应用编程接口。VFS是一个可以让open()、read()、write()等系统调用不用关心底层的存储介质和文件系统类型就可以工作的粘合层。







0- std::in

1- std::out

2-std::error





FILE* 结构体

文件描述符是下标



记录每个进程对文件的访问位置及权限



另外，该进程可通过在系统表中增加一项， 指向通向的v0node.实现同一文件进程共享。



---



BOF Begin of File

EOF End of File

[文件头                                        文件尾]



#define O_WRONLY(读写)   00000001

#define O_ROONLY(只读)    00000010

用按位或(逻辑加)`|`将权限组合





O_WRONLY | O_CREA } O_APPEND, 0644   组成逻辑加=>  操作控制字



















 