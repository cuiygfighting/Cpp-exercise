/*题目描述
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
输出描述:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序*/


//双指针技术，就是相当于有一个窗口，窗口的左右两边就是两个指针，
//我们根据窗口内值之和来确定窗口的位置和宽度
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> res;
		int plow = 1, phigh = 2;
		while (plow<phigh)
		{
			int cur = (phigh + plow)*(phigh - plow + 1) / 2;
			if (cur == sum)
			{
				vector<int> tmp;
				for (int i = plow; i <= phigh; i++)
					tmp.push_back(i);
				res.push_back(tmp);
				plow++;
			}
			else if (cur<sum) phigh++;
			else plow++;
		}
		return res;
	}
};