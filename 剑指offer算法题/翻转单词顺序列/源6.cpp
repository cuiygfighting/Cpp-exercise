/*题目描述
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？*/

class Solution {             //先翻转每个单词，再翻转整个句子
public:
	string ReverseSentence(string str) {
		int length = str.length();
		int low = 0, high = 0, i = 0;
		while (i<length)
		{
			while (i<length&&str[i] == ' ')  //找到单词第一个字母
				i++;
			low = high = i;
			while (i<length&&str[i] != ' ')  //找到单词后第一个空格
			{
				high++; i++;
			}
			ReverseWord(str, low, high - 1);
		}
		ReverseWord(str, 0, length - 1);
		return str;
	}

	void ReverseWord(string &str, int low, int high)
	{
		while (low<high)
			swap(str[low++], str[high--]);
	}
};