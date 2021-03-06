// 812largest_triangle_area.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

class Solution {
public:
	double area(vector<int> p1, vector<int>p2, vector<int>p3) {
		double a, b, c, s;
		a = sqrt((p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]));
		b = sqrt((p1[0] - p3[0])*(p1[0] - p3[0]) + (p1[1] - p3[1])*(p1[1] - p3[1]));
		c = sqrt((p3[0] - p2[0])*(p3[0] - p2[0]) + (p3[1] - p2[1])*(p3[1] - p2[1]));
		s = (a + b + c) / 2;
		return s * (s - a)*(s - b)*(s - c);
	}
	double largestTriangleArea(vector<vector<int>>& points) {
		double _max = 0;
		for (size_t i = 0; i < points.size(); i++)
			for (size_t j = i + 1; j < points.size(); j++)
				for (size_t k = j + 1; k < points.size(); k++)
					if (area(points[i], points[j], points[k]) > _max)
						_max = area(points[i], points[j], points[k]);
		return sqrt(_max);
	}
};


int main()
{
	vector<vector<int>> points = { { 0,0 },{ 0,1 },{ 1,0 },{ 0,2 },{ 2,0 } };
	Solution s;
	cout << s.largestTriangleArea(points);

	return 0;
}

