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
    bool isSymmetric(TreeNode* root) {
        if(root)
            return isSymmetricImpl(root->left, root->right);
        return true;
    }
    
    bool isSymmetricImpl(TreeNode* left, TreeNode* right){
        if(left==NULL && right == NULL)
            return true;
        else if(left == NULL || right == NULL)
            return false;
        else if(left->val != right->val)
            return false;
        else
            return isSymmetricImpl(left->left, right->right) && isSymmetricImpl(left->right, right->left);
    }
};
