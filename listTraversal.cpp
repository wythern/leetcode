#include "common.h"

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (NULL == head)
			return NULL;

		ListNode* pFakeHead = new ListNode(INT_MIN);
		pFakeHead->next = head;
		ListNode* pNode = head->next;
		int n = 2;
		head->next = NULL;
		while (pNode != NULL)
		{
			ListNode* pNextNode = pNode->next;
			insertionSortListImpl(pFakeHead, n, pNode);
			pNode = pNextNode;
			++n;
		}

		ListNode* pNewhead = pFakeHead->next;
		delete pFakeHead;
		return pNewhead;
	}

	void insertionSortListImpl(ListNode* head, int n, ListNode* pNewNode){
		int i = 1;
		ListNode* pNode = head->next;
		ListNode* pPrev = head;
		while (i < n)
		{
			if (pNode->val < pNewNode->val){
				pPrev = pNode;
				pNode = pNode->next;
				++i;
			}else{
				break;
			}
		}

		ListNode* pTmp = pPrev->next;
		pPrev->next = pNewNode;
		pNewNode->next = pTmp;
	}


	vector<int> postorderTraversal(TreeNode* root) {
		postorderTraversalImpl(root);
		return m_postOrder;
	}

	void postorderTraversalImpl(TreeNode* root) {
		if (NULL == root)
			return;

		if (root->left) postorderTraversal(root->left);
		if (root->right) postorderTraversal(root->right);
		m_postOrder.push_back(root->val);
	}

	vector<int> preorderTraversal(TreeNode* root) {

	}

	ListNode* sortList(ListNode* head) {
		int N = 0;
		ListNode* pNode = head;
		while (pNode != NULL)
		{
			pNode = pNode->next;
			++N;
		}

		return sortListImpl(head, N);
	}

	ListNode* sortListImpl(ListNode* head, int N){
		if (head == NULL || head->next == NULL || 1 == N)
			return head;

		int i = N / 2 ;
		ListNode* pLeft = head;
		ListNode* pRight = head;
		while (--i){
			pRight = pRight->next;
		}
		ListNode* pNode = pRight->next;
		pRight->next = NULL;
		pLeft = sortListImpl(pLeft, N / 2);
		pNode = sortListImpl(pNode, N - N / 2);
		pRight = pNode;

		ListNode* pNewHeader = NULL;
		if (pLeft->val < pRight->val){
			pNewHeader = pLeft;
			pLeft = pLeft->next;
		}else{
			pNewHeader = pRight;
			pRight = pRight->next;
		}
		pNode = pNewHeader;
		while (pLeft != NULL && pRight != NULL)
		{
			if (pLeft->val < pRight->val){
				pNode->next = pLeft;
				pLeft = pLeft->next;
			}
			else{
				pNode->next = pRight;
				pRight = pRight->next;
			}
			pNode = pNode->next;
		}

		pNode->next = (pLeft != NULL) ? pLeft : pRight;

		return pNewHeader;
	}

private:
	vector<int> m_postOrder;
};

int main(int argc, char** argv){
	ListNode node;
	int A[] = { 1, 2, -5, 3, -2, 9, 120, 111, 99, 72, 89};
	//int A[] = { 3 };
	node.from(A, sizeof(A) / sizeof(int));
	Solution s;
	node.dump();
	s.insertionSortList(&node)->dump();
	return 0;
}