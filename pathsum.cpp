/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "common.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;
        
        bool ret = (sum - root->val == 0) && (!root->left) && (!root->right);
        if(!ret && root->left) ret = hasPathSum(root->left, sum - root->val);
        if(!ret && root->right) ret = hasPathSum(root->right, sum - root->val);
        return ret;
    }

    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > vResults;
        vector<int> v;
        if(root)
            pathSumImpl(root, sum, vResults, v);
        return vResults;
    }

    bool pathSumImpl(TreeNode* root, int sum, vector<vector<int> >& vResults, vector<int>& v){
        bool ret = (sum - root->val == 0) && (!root->left) && (!root->right);
        v.push_back(root->val);
        if(ret)
            vResults.push_back(v);

        if(root->left) ret = pathSumImpl(root->left, sum - root->val, vResults, v);
        if(root->right) ret = pathSumImpl(root->right, sum - root->val, vResults, v);
        v.pop_back();

        return ret;
    }
};

int main(int argc, char** argv){
    Solution s;
    return 0;
}
