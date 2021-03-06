// 830positions_of_large_groups.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
In a string S of lowercase letters, these letters form consecutive groups of the same character.
For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".
Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.
The final answer should be in lexicographic order.
*/

class Solution {
public:
	vector<vector<int>> largeGroupPositions(string S) {
		int start = S.size(), _end = 0, count = 1;
		if (start <= 2) {
			return vector<vector<int>>({});
		}
		bool mark = false;
		vector<vector<int>> ans;
		for (size_t i = 1; i < S.size(); i++)
		{
			if (S[i] == S[i - 1])
				count++;
			if (count == 3 && mark == false)
			{
				start = i - 2;
				mark = true;
			}
			if (S[i] != S[i - 1]) {
				count = 1;
				mark = false;
				_end = i - 1;
				if (start<_end)
				{
					cout << "[" << start << "," << _end << "]\n";
					ans.push_back(vector<int>({ start, _end }));
					start = S.size();
				}
			}
		}
		if (count >= 3)
		{
			ans.push_back(vector<int>({ start, start + count - 1 }));
			cout << "[" << start << "," << start + count - 1 << "]\n";
		}
		return ans;
	}
};

int main()
{
	Solution s;
	s.largeGroupPositions("aaaaaaa");
	return 0;
}


