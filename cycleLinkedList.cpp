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
	ListNode* hasCycle(ListNode *head) {
		if (NULL == head)
			return false;

		ListNode* pIronman = head->next;
		ListNode* pHulk = head;

		while (pHulk != pIronman && pHulk != NULL && pIronman != NULL){
			pHulk = pHulk->next;
			pIronman = pIronman->next;
			if (NULL != pIronman)
				pIronman = pIronman->next;
		}

		return (pHulk == pIronman) ? pHulk : NULL;
	}

	ListNode *detectCycle(ListNode *head) {
		ListNode* pNodeInCycle = hasCycle(head);
		if (pNodeInCycle == NULL)
			return NULL;

		ListNode* pCycleBeginNode = head;
		ListNode* pHulk = pNodeInCycle;

		while (pCycleBeginNode != pHulk){
			pHulk = pHulk->next;
			if (pHulk == pNodeInCycle)
				pCycleBeginNode = pCycleBeginNode->next;
		}

		// TO LEARN:
		// other easier way is to using 2 pointer (head, tail) with cycle_length distance to
		// traversal the whole list, and you will see head == tail when head first comes to
		// the start point of the cycle.
		return pCycleBeginNode;
	}

};

int main(int argc, char** argv){
	ListNode vNode;
	int A[] = { 1, 2, 3, 4, 5, 6 };
	vNode.from(A, sizeof(A) / sizeof(int));
	vNode.tail->next = &vNode;
	Solution s;
	ListNode* pNode = s.detectCycle(&vNode);

	if (pNode)
		pfcout << pNode->val;
	return 0;
}