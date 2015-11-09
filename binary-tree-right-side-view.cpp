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
	vector<int> rightSideView(TreeNode* root) {
		if (!root)
			return vector<int>();

		list<TreeNode*> fifoUpper;
		list<TreeNode*> fifoLower;
		vector<int> vNodeView;

		bool bLvDone = false;
		fifoUpper.push_back(root);
		while (!fifoUpper.empty()){
			TreeNode* pNode = fifoUpper.front();
			fifoUpper.pop_front();

			if (!bLvDone){
				vNodeView.push_back(pNode->val);
				bLvDone = true;
			}

			if (pNode->right) fifoLower.push_back(pNode->right);
			if (pNode->left) fifoLower.push_back(pNode->left);

			if (fifoUpper.empty()){
				swap(fifoUpper, fifoLower);
				bLvDone = false;
			}
		}

		return vNodeView;
	}

	bool isLeaf(TreeNode* root){
		return (root->left == NULL) && (root->right == NULL);
	}
};


int main(int argc, char** argv){
	Solution s;
	int A[] = { 1, 2, 3, 4, 5 };
	TreeNode tree(A, sizeof(A) / sizeof(A[0]));
	vector<int> view = s.rightSideView(&tree);
	printContainer<vector<int> >(view, view.size(), "view");
	return 0;
}