// 804unique_morse_code_words.cpp: 定义控制台应用程序的入口点。
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
	int uniqueMorseRepresentations(vector<string>& words) {
		///words = ["gin", "zen", "gig", "msg"]
		const vector<string> morse{ ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
		vector<string> code;
		for (size_t i = 0; i < words.size(); i++)
		{
			code.push_back("");
			for (size_t j = 0; j < words.at(i).size(); j++)
				code.at(i).append(morse.at(words.at(i).at(j) - 'a'));
		}
		set<string> ans(code.begin(), code.end());
		return ans.size();
	}
};

int main()
{
	vector<string> words = { "gin", "zen", "gig", "msg" };
	Solution sol;
	sol.uniqueMorseRepresentations(words);
	return 0;
}

