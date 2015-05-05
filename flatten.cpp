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
    void flatten(TreeNode* root) {
        if(root)
            flattenImpl(root);
    }
    
    void flattenImpl(TreeNode* root){
        if(root->left)
            flattenImpl(root->left);
        if(root->right)
            flattenImpl(root->right);
        if(root->left){
            TreeNode* pRightNode = root->right;
            root->right = root->left;
            TreeNode* pLeftTail = root->left;
            root->left = NULL;
            while(pLeftTail->right)
                pLeftTail = pLeftTail->right;
            pLeftTail->right = pRightNode;
        }
    }
};
