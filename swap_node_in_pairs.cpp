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
};

int main(int argc, char** argv)
{
    Solution s;
	int n = 2;
	if(argc > 1)
		n = atoi(argv[1]);

	vector<int> vInts(generateRandomIntVector(n, 1, 10));
	ListNode vNode(vInts);
	vNode.dump();
	ListNode* pList = s.swapPairs(&vNode);
	pList->dump();
	return 0;
}

