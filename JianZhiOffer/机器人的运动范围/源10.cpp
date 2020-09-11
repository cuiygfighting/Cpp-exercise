/*题目描述
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和
大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？*/

class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		bool* flag = new bool[rows*cols];
		for (int i = 0; i<rows*cols; i++)
			flag[i] = false;
		int count = moving(threshold, rows, cols, 0, 0, flag);//从（0,0）坐标开始访问;
		delete[] flag;
		return count;
	}
	//计算最大移动位置
	int moving(int threshold, int rows, int cols, int i, int j, bool* flag)
	{
		int count = 0;
		if (check(threshold, rows, cols, i, j, flag))
		{
			flag[i*cols + j] = true;
			//标记访问过，这个标志flag不需要回溯，因为只要被访问过即可。
			//因为如果能访问，访问过会加1.不能访问，也会标记下访问过。
			count = 1 + moving(threshold, rows, cols, i - 1, j, flag)
				+ moving(threshold, rows, cols, i, j - 1, flag)
				+ moving(threshold, rows, cols, i + 1, j, flag)
				+ moving(threshold, rows, cols, i, j + 1, flag);
		}
		return count;
	}
	//检查当前位置是否可以访问
	bool check(int threshold, int rows, int cols, int i, int j, bool* flag)
	{
		if (i >= 0 && i<rows && j >= 0 && j<cols
			&& getSum(i) + getSum(j) <= threshold
			&& flag[i*cols + j] == false)
			return true;
		return false;
	}
	//计算位置的数值
	int getSum(int number)
	{
		int sum = 0;
		while (number>0)
		{
			sum += number % 10;
			number /= 10;
		}
		return sum;
	}
};