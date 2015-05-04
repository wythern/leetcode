class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        
        int h = 0;
        return BalancedHeight(root, h);
    }
    
    bool BalancedHeight(TreeNode* root, int& h){
        if(!root){
            h = 0;
            return true;
        }
        
        bool bBlanced = false;
        int l = h + 1;
        int r = h + 1;
        bBlanced = BalancedHeight(root->left, l);
        if(bBlanced)
            bBlanced = BalancedHeight(root->right, r);
        h = max(l, r);
        return bBlanced && ((l - r) >= -1 && (l - r) <= 1);
    }
};

