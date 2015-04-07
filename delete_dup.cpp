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
	ListNode *deleteDuplicates(ListNode *head) {
		ListNode* pHead = NULL;
		ListNode* pTail = NULL;
		ListNode* pCurr = head;
		while(pCurr != NULL && pCurr->next != NULL){
			if(pCurr->val != pCurr->next->val){
				if(NULL == pHead){
					pHead = pCurr;
					pTail = pHead;
				}else{
					pTail->next = pCurr;
					pTail = pCurr;
				}
			}

			pCurr = pCurr->next;
		}

		if(NULL == pHead){
			pHead = pCurr;
			pTail = pHead;
		}else{
			pTail->next = pCurr;
			pTail = pCurr;
		}

		return pHead;
    }

    ListNode *deleteDuplicates_remove_if_has_dups(ListNode *head) {
		ListNode* pHead = NULL;
		ListNode* pTail = NULL;
		ListNode* pCurr = head;
		bool bDup = false;
		while(pCurr != NULL && pCurr->next != NULL){
			if(pCurr->val != pCurr->next->val){
				if(!bDup){
					if(NULL == pHead){
						pHead = pCurr;
						pTail = pHead;
					}else{
						pTail->next = pCurr;
						pTail = pCurr;
					}
				}
				bDup = false;
			}else{
				bDup = true;
			}
			pCurr = pCurr->next;
		}

		if(!bDup){
			if(NULL == pHead){
				pHead = pCurr;
				pTail = pHead;
			}else{
				pTail->next = pCurr;
				pTail = pCurr;
			}
		}else{
			if(pTail != NULL)
				pTail->next = NULL;
		}

		return pHead;
    }
};

int main(int argc, char** argv){
	int p[] = {1, 1, 2, 3, 3, 3};
	ListNode list(p, sizeof(p)/sizeof(int));
	Solution s;
	ListNode* newList = s.deleteDuplicates(&list);
	newList->dump();
	return 0;
}
