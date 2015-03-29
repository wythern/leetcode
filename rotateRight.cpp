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
    ListNode *rotateRight(ListNode *head, int k) {
		if(head == NULL || k < 0)
			return NULL;

		ListNode* pLowerBound = head;
		ListNode* pUpperBound = head;
		int l = 0;
		int i = k;
		while(i--){
			pUpperBound = pUpperBound->next;
			l++;
			if(pUpperBound == NULL){
				pUpperBound = head;
				break;
			}
		}

		if (k > l){
			i = k % l;
			while(i--){
				pUpperBound = pUpperBound->next;
				l++;
				if(pUpperBound == NULL){
					pUpperBound = head;
					break;
				}
			}
		}

		while(pUpperBound->next != NULL){
			pLowerBound = pLowerBound->next;
			pUpperBound = pUpperBound->next;
		}
		pUpperBound->next = head;
		ListNode* newHead = pLowerBound->next;
		pLowerBound->next = NULL;

		return newHead;
    }
};

int main(int argc, char** argv){
	if(argc <= 1)
		exit(0);

	int A[] = {1,2,3,4,5};
	ListNode node;
	node.from(A, sizeof(A)/sizeof(A[0]));
	Solution s;
	node.dump();
	ListNode* rNode = s.rotateRight(&node, atoi(argv[1]));
	rNode->dump();
	return 0;
}
