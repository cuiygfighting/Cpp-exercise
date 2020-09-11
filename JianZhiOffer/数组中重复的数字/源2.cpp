/*题目描述
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2*/

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (length<1) return false;
		for (int i = 0; i<length; i++)
		{
			while (i != numbers[i])
			{
				if (numbers[i] == numbers[numbers[i]])
				{
					*duplication = numbers[i];
					return true;
				}
				int tmp = numbers[i];
				numbers[i] = numbers[numbers[i]];
				numbers[tmp] = tmp;
			}
		}
		return false;
	}
};
//此法利用了哈希的特性，但不需要额外的存储空间。 
因此时间复杂度为O(n)，不需要额外空间！
把当前序列当成是一个下标和下标对应值是相同的数组；
遍历数组，判断当前位的值和下标是否相等： 2.1.若相等，则遍历下一位；
2.2.若不等，则将当前位置i上的元素和a[i]位置上的元素比较：若它们相等，则成功！
若不等，则将它们两交换。换完之后a[i]位置上的值和它的下标是对应的，
但i位置上的元素和下标并不一定对应；重复2.2的操作，直到当前位置i的值也为i，
将i向后移一位，再重复2.


//思路1：哈希法
由于所有元素值是有范围的，因此可以用一个长度为n的数组，下标表示序列中的每一个值，下标对应的值表示该下标出现的次数。
只需扫描一次原序列，就统计出所有元素出现的次数；
再扫描一次哈希数组，找到一个出现次数大于1的值即可。
这种方法时间复杂度和空间复杂度都为O(n)。
public boolean duplicate(int array[], int length, int[] duplication) {
	if (array == null) return false;

	// 判断数组是否合法（每个数都在0~n-1之间）
	for (int i = 0; i<length; i++) {
		if (array[i]<0 || array[i]>length - 1) {
			return false;
		}
	}

	// key step
	int[] hash = new int[length];
	for (int i = 0; i<length; i++) {
		hash[array[i]]++;
	}
	for (int i = 0; i<length; i++) {
		if (hash[i]>1) {
			duplication[0] = i;
			return true;
		}
	}
	return false;
}