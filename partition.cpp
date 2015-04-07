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
    ListNode *partition(ListNode *head, int x) {
		ListNode* pNode = head;
		ListNode* pSBegin = NULL;
		ListNode* pSEnd = NULL;
		ListNode* pLBegin = NULL;
		ListNode* pLEnd = NULL;
		while(pNode != NULL){
			if(pNode->val < x){
				if(pSBegin == NULL){
					pSBegin = pNode;
					pSEnd = pSBegin;
				}else{
					pSEnd->next = pNode;
					pSEnd = pNode;
				}
			}else{
				if(pLBegin == NULL){
					pLBegin = pNode;
					pLEnd = pLBegin;
				}else{
					pLEnd->next = pNode;
					pLEnd = pNode;
				}
			}
			pNode = pNode->next;
		}

		//pSBegin->dump();
		//pLBegin->dump();

		if(pSBegin != NULL){
			pSEnd->next = pLBegin;
			if(pLEnd != NULL) pLEnd->next = NULL;
			return pSBegin;
		}else if (pLBegin != NULL){
			pLEnd->next = NULL;
			return pLBegin;
		}else{
			return head;
		}
	}
};

int main(int argc, char** argv){
	//int p[] = {1, 4, 3, 2, 5, 2};
	int p[] = {5, 4, 3, 1, 2, 2};
	Solution s;
	ListNode list(p, sizeof(p)/sizeof(int));
	ListNode* head = s.partition(&list, 3);
	head->dump();
	return 0;
}
