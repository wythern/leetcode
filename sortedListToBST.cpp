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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBstImpl(num.begin(), num.end());
    }
    
    TreeNode *sortedArrayToBstImpl(vector<int>::iterator itBegin, vector<int>::iterator itEnd){
        if(itBegin >= itEnd)
            return NULL;

        vector<int>::iterator itHalf = itBegin + (distance(itBegin, itEnd) - 1)/2;
        int val = *(itHalf);
        TreeNode* pRoot = new TreeNode(val);
        pRoot->left = sortedArrayToBstImpl(itBegin, itHalf);
        pRoot->right = sortedArrayToBstImpl(itHalf + 1, itEnd);
        return pRoot;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        return sortedListToBSTImpl(head, NULL);
    }
    
    TreeNode *sortedListToBSTImpl(ListNode *head, ListNode *tail){
        if(head == tail)
            return NULL;

        ListNode* p1step = head;
        ListNode* p2step = head;
        
        while(p2step != tail){
            p2step = p2step->next;
            if(p2step != tail){
                p1step = p1step->next;
                p2step = p2step->next;
            }
        }
        TreeNode* pRoot = new TreeNode(p1step->val);
        pRoot->left = sortedListToBSTImpl(head, p1step);
        pRoot->right = sortedListToBSTImpl(p1step->next, tail);
        return pRoot;
    }

};


