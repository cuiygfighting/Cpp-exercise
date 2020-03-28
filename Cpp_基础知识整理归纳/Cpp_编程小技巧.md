## 1.常用小技巧

```c++
1.将数字将换成字符：
{
	char c; int a;
c = a + '0';
}

2.怎么使控制台exe.运行完程序后不退出：
在return(0)前面加上while(1)或者system('pause')或者getchar()

3.for(;(c=getchar())!='\n';)  cout<<c;
输入一个字符后立即输出该字符，直到遇到换行符为止
请注意：从终端键盘向计算机输入时,是在按Enter键以后才送到内存缓冲区。程序在执行过程中，会去内存缓冲区读取需要的数据。

4.for (int i = 0; i < 10; i++)  cin >> a[i]：这种可以直接输入十个数，也可以一个一个输入

5.const char  *p;					//使用字符指针时必须把指针定义为const
p = "I love china!";			    //字符串常量不用加取地址
cout << p << endl;
```

## 2.关于头文件的引用

在另一个源文件定义函数时需要把涉及到的声明全部include进来，需要用到输入输出时需要把(#include <iostream>,using namespace写上)。

在在另一个源文件中定义类的函数时需要把类的声明包含进来。且自己定义的类的声明后面必须加.h(#include <sort.h>)

