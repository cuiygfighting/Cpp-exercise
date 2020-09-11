/*题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy*/
class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL || length<1) return;
		int Oldlength = 0;
		int Newlength = 0;
		int count = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == ' ')
				count++;
			Oldlength++;   //Oldlength为不包含空字符的原字符串的元素个数
		}
		Newlength = Oldlength + 2 * count;//Newlength为不包含空字符的新字符串的元素个数
		if (Newlength + 1>length) return;
		for (; Oldlength >= 0 && Newlength>Oldlength; Oldlength--)//从后向前原地替换空格
		{
			if (str[Oldlength] == ' ')
			{
				str[Newlength--] = '0';
				str[Newlength--] = '2';
				str[Newlength--] = '%';
			}
			else
				str[Newlength--] = str[Oldlength];
		}
	}
};