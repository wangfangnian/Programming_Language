// 540single_element_in_a_sorted_array.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int retval;
		for (size_t i = 0; i < nums.size()-1; i+=2)
		{
			if (nums[i] != nums[i + 1]) {
				return nums[i];
			}
		}
		return nums[nums.size() - 1];
	}
};
/*
int left = 0, right = nums.size()-1;
		int mid;
		while (left<right)
		{
			mid=((left + right) / 2);
			if (mid % 2 == 0) {
				if (nums[mid] == nums[mid + 1])
					left = mid;
				else if(nums[mid]==nums[mid-1])
					right = mid ;
				else
					break;
			}
			else {
				if (nums[mid] == nums[mid - 1])
					left = mid;
				else if (nums[mid] == nums[mid + 1])
					right = mid;
				else
					break;

			}
		}
		retval = mid;
		return nums[mid];
*/

//another binary search 
int main()
{
	vector<int> nums{ 3,3,5 };
	Solution solution;
	cout << solution.singleNonDuplicate(nums) << endl;;

	vector<int> nums2{ 3,3,7,7,10,11,11 };
	Solution solution2;
	cout << solution2.singleNonDuplicate(nums2);

    return 0;
}

