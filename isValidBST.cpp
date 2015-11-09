#include "common.h"
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if(NULL == root)
            return true;
        
        m_bInit = false;
        m_prev = INT_MIN;
        return traversal(root);        
    }
    
    bool traversal(TreeNode* root){
        int lastVal = 0;
        bool ret = true;
        if(root->left)
            ret &= traversal(root->left);
        
        if(m_bInit && m_prev >= root->val)
            return false;

        m_bInit = true;
        m_prev = root->val;
        if(ret && root->right)
            ret &= traversal(root->right);

        return ret;
    }
    
private:
    bool m_bInit;
    int m_prev;
};

int main(int argc, char** argv){
	int A[] = {1, #, 2, 3};
	Solution s;
	TreeNode tree;
	tree.from(A, 4);
	tree.dump();
	
	//printContainer<vector<int> >(A, A.size(), "A");
	return 0;
}
