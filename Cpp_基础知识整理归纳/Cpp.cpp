1.将数字将换成字符：
{
	char c; int a;
c = a + '0';
}

2.怎么使控制台exe.运行完程序后不退出：
在return(0)前面加上while(1)或者system('pause')或者getchar

3.for (int i = 0; i < 10; i++)  cin >> a[i]：这种可以直接输入十个数，也可以一个一个输入

4.#include<iostream>    
using namespace std;		 //在外部文件中定义函数时使用输入输出流必须加上这两句
void waibu(void)                //可以通过头文件或者外部函数的方式把函数定义放在外部
{
	cout << a << endl;
}

5.const char  *p;					//使用字符指针时必须在把指针定义为const
p = "I love china!";			    //字符串常量不用加取地址
cout << p << endl;
return 0;
#
#
