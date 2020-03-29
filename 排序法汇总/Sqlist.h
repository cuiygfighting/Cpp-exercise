#define max 20
typedef struct
{
	double number[max+1];      //number[0]用于存放数组长度或者存储临时变量
	int length;
}Sqlist, *SqVector; 
