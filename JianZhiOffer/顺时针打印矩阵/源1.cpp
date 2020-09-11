/*题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.*/

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> value;
		if (matrix.size() == 0) return value;
		int row = matrix.size();
		int col = matrix[0].size();
		int left = 0, right = col - 1, top = 0, bottom = row - 1;
		while (left <= right && top <= bottom)
		{
			for (int i = left; i <= right; i++) value.push_back(matrix[top][i]);
			for (int i = top + 1; top <= bottom; i++) value.push_back(matrix[i][right]);
			if (top<bottom)
				for (int i = right - 1; i >= left; i--) value.push_back(matrix[bottom][i]);
			if (left<right)
				for (int i = bottom - 1; i >= top + 1; i--) value.push_back(matrix[i][left]);
			left++, right--, top++, bottom--;
		}
		return value;
	}
};