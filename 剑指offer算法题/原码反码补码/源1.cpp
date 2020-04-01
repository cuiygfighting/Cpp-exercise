/*题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。*/
class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		int flag = 1;
		while (flag != 0)
		{
			if ((n&flag) != 0) count++;
			flag = flag << 1;
		}
		return count;
	}
};


/*首先判断n是不是负数，当n为负数的时候，直接用后面的while循环会导致死循环，因为负数
向左移位的话最高位补1 ！ 因此需要一点点特殊操作，可以将最高位的符号位1变成0，也就
是n & 0x7FFFFFFF，这样就把负数转化成正数了，唯一差别就是最高位由1变成0，因为少了
一个1，所以count加1。之后再按照while循环里处理正数的方法来操作就可以啦*/
class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		if (n < 0) {
			n = n & 0x7FFFFFFF;
				++count;
		}
		while (n != 0) {
			count += n & 1;
			n = n >> 1;
		}
		return count;
	}
};

//--------------------最优解----------------------------
class Solution {
public :
	static int NumberOf1(int n) {
		int count = 0;
		while (n != 0) {
			++count;
			n = (n - 1) & n;
		}
		return count;
	}
};