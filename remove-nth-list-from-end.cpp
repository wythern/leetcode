#include "common.h"
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(NULL == head || 0 == n)
            return head;

        ListNode* pLowerBound = head;
        ListNode* pUpperBound = head;
        int span = n;
		bool bValidRemove = false;
        while(pUpperBound != NULL){
            pUpperBound = pUpperBound->next;
            if(!span){
                pLowerBound = pLowerBound->next;
			}
			else
				span--;
        }

        if(!span)
			pLowerBound->next = pLowerBound->next->next;
		else if(span == 1)
			return head->next;

		return head;
    }

	ListNode *removeNthFromEnd1(ListNode *head, int n) {
        if(NULL == head || 0 == n)
            return head;

        ListNode* pFront = head;
        ListNode* pBack = head;
        int span = n+1;
        while(pFront != NULL){
			pFront = pFront->next;
			if(!span){
                pBack = pBack->next;
			}
			else
				--span;
        }

		if(!span)
			pBack->next = pBack->next->next;
		else if(pBack == head)
			return head->next;

		return head;
    }
};

int main(int argv, char** argc)
{
	Solution s;
	int A[] = {1,2,3,4,5,6,7};
	ListNode* head = new ListNode(A, sizeof(A)/sizeof(int));
	head->dump();
	int n = 0;
	if(argv > 1)
		n = atoi(argc[1]);

	ListNode* p2 = s.removeNthFromEnd1(head, n);
	p2->dump();
	return 0;
}
