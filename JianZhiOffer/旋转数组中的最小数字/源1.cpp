/*题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。*/

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty()) return 0;
		int low = 0, high = rotateArray.size() - 1, mid = 0;
		while (low<high)
		{
			if (rotateArray[low]<rotateArray[high]) break;
			mid = low + (high - low) / 2;
			if (rotateArray[low]<rotateArray[mid])
				low = mid + 1;
			else if (rotateArray[high]>rotateArray[mid])
				high = mid;
			else low++;
		}
		return rotateArray[low];
	}
};


//运用sort函数
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		sort(rotateArray.begin(), rotateArray.end());

		return rotateArray[0];

	}
};