/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "common.h"

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
		if(NULL == head || NULL == head->next)
			return head;

		ListNode* pFront = head;
		ListNode* pBack = head->next;
		pFront->next = swapPairs(pBack->next);
		pBack->next = pFront;
		return pBack;
    }

	ListNode *swapKPairs(ListNode *head, int k) {
		if(NULL == head)
			return head;

		ListNode* p = head;
		int c = 0;

		while(p != NULL && c < k){
			p = p->next;
			c++;
		}

		if(p == NULL && c != k)
			return head;

		p = head;
		c = 0;

		ListNode* pPrev = NULL;
		ListNode* pNext = head->next;
		while(c < k && p != NULL){
			pNext = p->next;
			p->next = pPrev;
			pPrev = p;
			p = pNext;
			c++;
		}

		head->next = swapKPairs(p, k);
		return pPrev;
    }
};

int main(int argc, char** argv)
{
    Solution s;
	int n = 2;
	int k = 2;
	if(argc > 2){
		n = atoi(argv[1]);
		k = atoi(argv[2]);
	}

	vector<int> vInts(generateRandomIntVector(n, 1, 10));
	ListNode vNode(vInts);
	vNode.dump();
	ListNode* pList = s.swapKPairs(&vNode, k);
	pList->dump();
	return 0;
}

