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
	int sumNumbers(TreeNode* root) {
		if (!root)
			return 0;
		return traversal(root, 0);
	}

	int traversal(TreeNode* root, int prev_digit){
		if (isLeaf(root))
			return root->val + prev_digit * 10;

		int digit = root->val + prev_digit * 10;
		int sum = 0;
		if (root->left) sum = traversal(root->left, digit);
		if (root->right) sum += traversal(root->right, digit);

		return sum;
	}

	bool isLeaf(TreeNode* root){
		return (root->left == NULL) && (root->right == NULL);
	}
};

int main(int argc, char** argv){
	Solution s;
	int A[] = {1, 2, 3, 4, 5};
	TreeNode tree(A, sizeof(A)/sizeof(A[0]));
	int c = s.sumNumbers(&tree);
	printf("c = %d.\n", c);
	return 0;
}