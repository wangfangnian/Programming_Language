// 728self_dividing_numbers.cpp: 定义控制台应用程序的入口点。
//

// For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> dived;
		string num;
		int ans = 0, number, ans1 = 0;
		for (int i = left; i <= right; i++) {
			ans = 0;
			number = i;
			//to_string(i).find("0") == std::string::npos
			int b = 1;
			while (true)
			{
				b = number % 10;
				if (b == 0)
					break;
				number /= 10;
				if (i%b != 0 || number % 10 == 0 && number != 0) {
					ans++;
					break;
				}
			}

			if (ans == 0 && i % 10 != 0) 
				dived.push_back(i);
		}
		return dived;
	}
};

int main()
{
	Solution solution;
	vector<int> divid;
	divid = solution.selfDividingNumbers(1, 1000);
	for each (int var in divid)
	{
		cout << var << " ";
	}

	return 0;
}

