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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *pDigitElementL1 = l1;
		ListNode *pDigitElementL2 = l2;
		ListNode *pReturnList = NULL;
		ListNode *pReturnListNode = NULL;
		int carry = 0;

		while(pDigitElementL1 != NULL ||
			  pDigitElementL2 != NULL){
			int nDigit = 0;
			if(pDigitElementL1 != NULL){
				nDigit += pDigitElementL1->val;
				pDigitElementL1 = pDigitElementL1->next;
			}

			if(pDigitElementL2 != NULL){
				nDigit += pDigitElementL2->val;
				pDigitElementL2 = pDigitElementL2->next;
			}
			
			nDigit += carry;
			carry = nDigit/10;
			nDigit %= 10;
			ListNode* pNode = new ListNode(nDigit);
			//printf("Digit(%d).", nDigit);

			if(pReturnList == NULL){
				pReturnList = pNode;
				pReturnListNode = pNode;
			}else{
				pReturnListNode->next = pNode;
				pReturnListNode = pReturnListNode->next;
			}
		}

		if(carry)
			pReturnListNode->next = new ListNode(carry);

		return pReturnList;
    }
};

int main(int argv, char** argc)
{
	Solution s;
	ListNode LA;
	ListNode LB;
	int A[] = {1, 3, 5, 7, 9};
	int B[] = {2, 4, 6, 8};

	LA.from(A, 5);
	LB.from(B, 4);

	LA.dump();
	LB.dump();
	ListNode* pList = s.addTwoNumbers(NULL, &LB);
	//printf("get list.\n");
	pList->dump();
	return 0;
}
