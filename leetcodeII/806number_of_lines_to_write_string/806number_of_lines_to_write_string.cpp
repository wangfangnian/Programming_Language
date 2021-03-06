// 806number_of_lines_to_write_string.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
	vector<int> numberOfLines(vector<int>& widths, string S) {
		int units = 0;
		int lines = 0;
		vector<int> ans;
		for (size_t i = 0; i < S.size(); i++)
		{
			if (units + widths.at(S.at(i) - 'a') > 100)
			{
				lines++;
				units = 0;
			}
			units += widths.at(S.at(i) - 'a');
		}
		ans.push_back(++lines);
		ans.push_back(units);
		//cout << lines << endl << units << endl;
		return ans;
	}
};

int main()
{
	vector<int> widths = { 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10 };
	string S = "abcdefghijklmnopqrstuvwxyz";

	vector<int> widths2 = { 4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10 };
	string S2 = "bbbcccdddaaa";

	Solution sol;
	sol.numberOfLines(widths, S);
	sol.numberOfLines(widths2, S2);
	return 0;
}


