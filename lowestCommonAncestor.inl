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
	TreeNode* lowestCommonAncestor_BST(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || !p || !q)
			return NULL;

		if (p->val >= q->val)
			std::swap(p, q);

		if (p->val <= root->val && q->val >= root->val)
			return root;

		if (q->val <= root->val)
			return lowestCommonAncestor(root->left, p, q);

		if (root->val <= p->val)
			return lowestCommonAncestor(root->right, p, q);
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || !p || !q)
			return NULL;

		vector<TreeNode*> inPathp;
		vector<TreeNode*> inPathq;

		if (inTreePath(root, p, inPathp) && inTreePath(root, q, inPathq)){
			int i = 0;
			int j = 0;
			while (i < inPathp.size() && j < inPathq.size()){
				if (inPathp[i] != inPathq[j])
					return inPathp[i - 1];
				++i;
				++j;
			}

			if (i == inPathp.size())
				return inPathp[i - 1];
			else //(j == inPathp.size())
				return inPathq[j - 1];
		}
	}

	bool inTreePath(TreeNode* root, TreeNode* p, vector<TreeNode*>& inPath){
		if (root == p){
			inPath.push_back(p);
			return true;
		}

		inPath.push_back(root);
		if (root->left && inTreePath(root->left, p, inPath))
			return true;
		
		if (root->right && inTreePath(root->right, p, inPath))
			return true;

		inPath.pop_back();
		return false;
	}
};

int main(int argc, char** argv){
	Solution s;
	int A[] = { 1, 2, 8, 3, '#', '#', '#', 4, '#', 5, '#', 6 };

	TreeNode tree(A, sizeof(A) / sizeof(int));

	TreeNode* p = tree.find(2);
	TreeNode* q = tree.find(8);

	pfcout << s.lowestCommonAncestor(&tree, p, q)->val;
	return 0;
}