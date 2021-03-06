// 110balanced_binary_tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

void CreatTree(TreeNode *&T) {
	int a;
	cin >> a;
	if (a == -1)
		T = NULL;
	else {
		T = new TreeNode(a);
		CreatTree(T->left);
		CreatTree(T->right);
	}
}

void PreOrder(TreeNode *T) {
	if (T != NULL)
	{
		cout << T->val << " ";
		PreOrder(T->left);
		PreOrder(T->right);
	}
}
class Solution {
public:
	int m_abs(int a, int b) {
		if (a > b)
			return a - b;
		return b - a;
	}
	int heightOfTree(TreeNode *t) {
		if (t == NULL)
			return 0;
		int Lh = heightOfTree(t->left);
		int Rh = heightOfTree(t->right);
		return Lh > Rh ? Lh + 1 : Rh + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;
		if (m_abs(heightOfTree(root->left),heightOfTree(root->right))>1)
		{
			return false;
		}
		return isBalanced(root->left) && isBalanced(root->right);
	}
};

int main()
{
	TreeNode *t;
	CreatTree(t);
	//3 9 -1 -1 20 15 -1 -1 7 -1 -1
	PreOrder(t);
	cout << Solution().isBalanced(t);
	
    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
