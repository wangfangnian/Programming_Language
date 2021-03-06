// 637average_of_levels_in_binary_tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class m_tree {
public:
	void creatTree(TreeNode *&t) {
		int a;
		cin >> a;
		if (a == -1)
			t = NULL;
		else
		{
			t = new TreeNode(a);
			creatTree(t->left);
			creatTree(t->right);
		}
	}
	void preOrder(TreeNode *&t) {
		if (t != NULL)
		{
			cout << t->val << " ";
			preOrder(t->left);
			preOrder(t->right);

		}
	}

};

class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> ans;
		if (root != NULL)
			levelOrder(root, ans);
		/*for (auto i : ans)
			cout << i<<" ";*/
		return ans;
	}
	void levelOrder(TreeNode *&t, vector <double> &ans) {
		queue<TreeNode *> tNode;
		tNode.push(t);
		while (!tNode.empty())
		{
			queue<TreeNode *> tmp;
			tmp = tNode;
			tNode = queue<TreeNode*>();
			double counter = 0;
			int num = 0;
			while (!tmp.empty())
			{
				counter += tmp.front()->val;
				num++;
				if (tmp.front()->left != NULL)
					tNode.push(tmp.front()->left);
				if (tmp.front()->right != NULL)
					tNode.push(tmp.front()->right);

				tmp.pop();
			}
			ans.push_back(counter / num);

		}
	}
};

int main()
{
	TreeNode *t;
	m_tree tree;
	tree.creatTree(t);
	//3 9 -1 -1 20 15 -1 -1 7 -1 -1
	tree.preOrder(t);
	Solution s;
	s.averageOfLevels(t);

	std::cout << "Hello World!\n";
}
