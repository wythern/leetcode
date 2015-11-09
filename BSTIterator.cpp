/*tion for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        stepTraversal(root);
        m_pNext = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(m_vStack.empty())
            return false;
            
        TreeNode* pNode = m_vStack.back();
        m_vStack.pop_back();
        stepTraversal(pNode->right);
        m_pNext = pNode;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        return m_pNext;
    }
private:
    void stepTraversal(TreeNode* root){
        if(!root){
            m_vStack.push_back(root);
            if(root->left)
                stepTraversal(root->left);
        }
    }

private:
    vector<TreeNode*> m_vStack;
    TreeNode*         m_pNext;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
