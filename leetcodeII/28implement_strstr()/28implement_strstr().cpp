// 28implement_strstr().cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	int strStr(string haystack, string needle) {
		return haystack.find(needle) >= 0 ? haystack.find(needle) : -1;
	}
};

int main()
{
    return 0;
}

