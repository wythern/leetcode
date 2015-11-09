#include "common.h"

using std::max;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        m_max = INT_MIN;
        return maxPathSumImpl(root);
    }
    
    int maxPathSumImpl(TreeNode* root){
        if(!root)
            return 0;

        if(root->val > m_max)
            m_max = root->val;

        int a = maxPathSumNode(root->left);
        int b = maxPathSumNode(root->right);
        int m = max(max(root->val, max(a + root->val, b + root->val)), a + b + root->val);
        if (m > m_max)
            m_max = m;
        return m_max;
    }
    
    int maxPathSumNode(TreeNode* root){
        if(!root)
            return 0;

        if(root->val > m_max)
            m_max = root->val;
        
        int a = maxPathSumNode(root->left);
        int b = maxPathSumNode(root->right);
        int m = max(max(root->val, max(a + root->val, b + root->val)), a + b + root->val);
        if(m > m_max)
            m_max = m;
        
        return max(root->val, max(a + root->val, b + root->val));
    }
    
private:
    int m_max;
};

int main(int argc, char** argv){
	Solution s;
    //int A[] = {1, -2, 3};
    int A[] = {1, -2, 3};
	TreeNode tree(A, 3);
	cout << "Max path Sum = " << s.maxPathSum(&tree) << endl;
	return 0;
}
