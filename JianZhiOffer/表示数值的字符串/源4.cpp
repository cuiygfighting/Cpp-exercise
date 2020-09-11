/*题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。*/

class Solution {
public:
	bool isNumeric(char* string)
	{
		bool sign = false, decimal = false, hasE = false;
		for (int i = 0; i<strlen(string); i++)
		{
			if (string[i] == '+' || string[i] == '-')
			{
				if (!sign&&i>0 && string[i - 1] != 'E'&&string[i - 1] != 'e') return false;
				// 第一次出现+-符号，且不是在字符串开头，则必须紧接在e之后
				else if (sign&&string[i - 1] != 'E'&&string[i - 1] != 'e') return false;
				// 第二次出现+-符号，则必须紧接在e之后
				sign = true;
			}
			else if (string[i] == '.')
			{
				if (i == 0) return false;
				//.不能在首位
				else if (hasE || decimal) return false;
				// Ee后面不能有小数点，小数点不能出现两次
				decimal = true;
			}
			else if (string[i] == 'e' || string[i] == 'E')
			{
				if (hasE) return false;
				//Ee不能出现两次
				else if (i == strlen(string) - 1) return false;
				//Ee不能在末尾
				hasE = true;
			}
			else if (string[i]>'9' || string[i]<'0') return false;
			//若是数学则必须在0-9之间
		}
		return true;
	}

};