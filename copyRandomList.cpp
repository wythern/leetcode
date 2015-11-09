#include "common.h"

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}

	static RandomListNode* from(int A[], int n){
		if (0 == n || NULL == A)
			return NULL;

		RandomListNode* pNode = new RandomListNode(A[0]);
		pNode->next = from(A + 1, n - 1);
		return pNode;
	}
};

/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random;
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (NULL == head)
			return NULL;


		if (mapRandom.find(head) != mapRandom.end()){
			return mapRandom[head];
		}

		RandomListNode* pNode = new RandomListNode(head->label);
		mapRandom[head] = pNode;
		pNode->next = copyRandomList(head->next);
		pNode->random = copyRandomList(head->random);
		return pNode;
	}

	map<RandomListNode*, RandomListNode*> mapRandom;
};

int main(int argc, char** argv){
	return 0;
}