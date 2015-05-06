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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return NULL;

        if(head->val == val)
            return removeElements(head->next, val);

        ListNode* pCurr = head->next;
        ListNode* pPrev = head;
        while(pCurr != NULL){
            if(pCurr->val == val)
                pPrev->next = pCurr->next;
            else
                pPrev = pCurr;
            pCurr = pCurr->next;
        }
        return head;
    }
};
