// 144binary_tree_preorder_traversal.cpp : 
// Given a binary tree, return the preorder traversal of its nodes' values.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

/// LeetCode 二叉树模板
/* 
*  struct TreeNode
*  string treeNodeToString(TreeNode* root)
*  void trimLeftTrailingSpaces(string &input)
*  void trimRightTrailingSpaces(string &input)
*  TreeNode* stringToTreeNode(string input)
*  void prettyPrintTree(TreeNode* node, string prefix = "", bool isLeft = true)
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string treeNodeToString(TreeNode* root) {
	if (root == nullptr) {
		return "[]";
	}

	string output = "";
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode* node = q.front();
		q.pop();

		if (node == nullptr) {
			output += "null, ";
			continue;
		}

		output += to_string(node->val) + ", ";
		q.push(node->left);
		q.push(node->right);
	}
	return "[" + output.substr(0, output.length() - 2) + "]";
}

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	if (!input.size()) {
		return nullptr;
	}

	string item;
	stringstream ss;
	ss.str(input);

	getline(ss, item, ',');
	TreeNode* root = new TreeNode(stoi(item));
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);

	while (true) {
		TreeNode* node = nodeQueue.front();
		nodeQueue.pop();

		if (!getline(ss, item, ',')) {
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int leftNumber = stoi(item);
			node->left = new TreeNode(leftNumber);
			nodeQueue.push(node->left);
		}

		if (!getline(ss, item, ',')) {
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int rightNumber = stoi(item);
			node->right = new TreeNode(rightNumber);
			nodeQueue.push(node->right);
		}
	}
	return root;
}

void prettyPrintTree(TreeNode* node, string prefix = "", bool isLeft = true) {
	if (node == nullptr) {
		cout << "Empty tree";
		return;
	}

	if (node->right) {
		prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
	}

	cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "\n";

	if (node->left) {
		prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
	}
}

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int>res;
		preOrder(root, res);
		return res;
	}
	void preOrder(TreeNode *root, vector<int> &res) {
		if (root != NULL)
		{
			res.push_back(root->val);
			preOrder(root->left, res);
			preOrder(root->right, res);
		}
	}
};

int main() {
	string line;
	while (getline(cin, line)) {
		TreeNode* root = stringToTreeNode(line);
		prettyPrintTree(root);
		for (auto var : Solution().preorderTraversal(root))
			cout << var << " ";
	}
	return 0;
}