// 589n-ary_tree_preorder_traversal.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
class Node
{
public:
	int val;
	vector<Node *> children;
	Node(int _val, vector<Node*>_children) {
		val = _val;
		children = _children;
	}

	Node() {};

};
class Solution {
public:
	vector<int>ans;
	vector<int> preorder(Node* root) {
		if (root == NULL)
			return ans;
		else {
			pre(root);
			return ans;
		}
	}
	void pre(Node *root) {
		if (root != NULL) {
			ans.push_back(root->val);
			for (auto i : root->children)
				preorder(i);
		}
	}
};
int main()
{
	std::cout << "Hello World!\n";
}
