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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int nA = countLength(headA);
		int nB = countLength(headB);

		if (nA > nB){
			std::swap(headA, headB);
			std::swap(nA, nB);
		}

		ListNode* pA = headA;
		ListNode* pB = headB;
		int offset = nB - nA;
		while (offset)
		{
			pB = pB->next;
			--offset;
		}

		while (pA != pB && pA != NULL)
		{
			pA = pA->next;
			pB = pB->next;
		}

		return pA;
	}

	int countLength(ListNode* head){
		int i = 0;
		while (head != NULL)
		{
			head = head->next;
			++i;
		}
		return i;
	}
};


int main(int argc, char** argv){
	ListNode A(1);
	ListNode* pB = NULL;
	Solution s;
	s.getIntersectionNode(&A, pB);

	return 0;
}