#include "common.h"


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> paths;
		if (!root)
			return paths;

		string str;
		ostringstream ss;
		ss << root->val;
		str = ss.str();
		if (root->left == NULL && root->right == NULL){
			paths.push_back(str);
			return paths;
		}

		string strRoot(str);
		binaryTreePathsImpl(root->left, str, paths);
		str = strRoot;
		binaryTreePathsImpl(root->right, str, paths);
		return paths;
	}

	void binaryTreePathsImpl(TreeNode* root, string& str, vector<string>& paths){
		if (root == NULL){
			return;
		}

		ostringstream ss;
		ss << "->" << root->val;
		str += ss.str();
		if (root->left == NULL && root->right == NULL){
			paths.push_back(str);
			return;
		}

		string strRoot(str);
		binaryTreePathsImpl(root->left, str, paths);
		str = strRoot;
		binaryTreePathsImpl(root->right, str, paths);
	}
};


int main(int argc, char** argv){
	int A[] = { 100, 200, 300, '#', 500 };
	TreeNode tree(A, sizeof(A) / sizeof(int));
	Solution s;
	vector<string> paths = s.binaryTreePaths(&tree);
	printArray(paths);
	return 0;
}