/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* l = new ListNode;
        if(NULL != l1)
            l = l1;

        ListNode* l1Iter = l1;
        ListNode* l2Iter = l2;
        while(NULL != l1Iter || NULL != l2Iter){
            int val = 0;
            if(NULL != l1Iter)
                val = l1Iter->val;
            if(NULL != l2Iter)
                val += l2Iter->val;
            
        }
    }
};
