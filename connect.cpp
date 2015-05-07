/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        
        list<TreeLinkNode*> upLv(1, root);
        list<TreeLinkNode*> downLv;
        while(!upLv.empty()){
            TreeLinkNode* pNode = upLv.front();
            upLv.pop_front();
            
            if(pNode->left) downLv.push_back(pNode->left);
            if(pNode->right) downLv.push_back(pNode->right);
            
            if(!upLv.empty())
                pNode->next = upLv.front();
            else
                swap(upLv, downLv);
        }
    }
};
