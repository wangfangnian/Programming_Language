// 556next_greater_element_III.cpp: 定义控制台应用程序的入口点。
//Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which
//has exactly the same digits existing in the integer n and is greater in value than n.If
// no such positive 32-bit integer exists, you need to return -1.

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <set>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
class Solution {
public:
	int nextGreaterElement(int n) {
		//char *s = new char;
		//sprintf(s, "%d", n);
		//string str(s);
		//sort(str.begin(), str.end());
		//set<int> num;
		//while (next_permutation(str.begin(),str.end()))//
		//	num.insert(atoi(str.data()));
		//set<int>::iterator it;
		//for (it = num.begin(); it != num.end(); it++) 
		//	if (*it > n)
		//		return *it;//输出结果是：0247
		//return -1;
		string digits = to_string(n);
		next_permutation(begin(digits), end(digits));
		long long res = stoll(digits);//stoll 将字符串转化为 long long 类型。
		return (res > INT_MAX || res <= n) ? -1 : res;
	}
};
int main()
{

	Solution solution;
	cout << solution.nextGreaterElement(1999999999) << endl;
	cout << solution.nextGreaterElement(2134) << endl;
	cout << solution.nextGreaterElement(1234) << endl;

	return 0;
}


