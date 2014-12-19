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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
		int k = lists.size();
		if(0 == k)
			return NULL;

		if(1 == k)
			return lists[0];

		if(2 == k)
			return merge2Lists(lists[0], lists[1]);

		vector<ListNode*> vNewLists;
		for(int i = 0; i < k - 1; i+=2){
			vNewLists.push_back(merge2Lists(lists[i], lists[i+1]));
		}

		if(k%2){
			vNewLists.push_back(lists[k-1]);
		}
#if 0
		std::cout << " >>>>>>>>>>>>>>>>>>>> " << vNewLists.size() << std::endl;
		for(int i = 0; i < vNewLists.size(); ++i){
			vNewLists[i]->dump();
		}
		std::cout << " <<<<<<<<<<<<<<<<<<<< " << std::endl;
#endif
		return mergeKLists(vNewLists);
    }

	ListNode *merge2Lists(ListNode * list1, ListNode* list2) {
		if(list1 == NULL || list2 == NULL)
			return (NULL == list1) ? list2 : list1;

		ListNode* pHead = (list1->val <= list2->val) ? list1 : list2;
		ListNode* pCursor = pHead;
		ListNode* pList1 = (pHead == list1) ? list1->next : list1;
		ListNode* pList2 = (pHead == list2) ? list2->next : list2;
		while(NULL != pList1 && NULL != pList2){
			if(pList1->val <= pList2->val){
				//ListNode* pTempNode = pCursor->next;
				//pCursor = pList1;
				pCursor->next = pList1;
				pList1 = pList1->next;
			}else{
				//ListNode* pTempNode = pCursor->next;
				//pCursor = pList2;
				pCursor->next = pList2;
				pList2 = pList2->next;
			}

			pCursor = pCursor->next;
		}

		if(NULL == pList1)
			pCursor->next = pList2;
		else
			pCursor->next = pList1;

		return pHead;
	}
};

int main(int argc, char** argv)
{
    Solution s;
	int n = 2;
	if(argc > 1)
		n = atoi(argv[1]);

	vector<ListNode*> vLists;
	vector<int> vRef;
	for(int i = 0; i < n; ++i){
		vector<int> vInts(generateRandomIntVector(3, 1, 10));
		vRef.insert(vRef.end(), vInts.begin(), vInts.end());
		std::sort(vInts.begin(), vInts.end());
		vLists.push_back(new ListNode(vInts));
	}

	ListNode* pList = s.mergeKLists(vLists);
	pList->dump();

	std::sort(vRef.begin(), vRef.end());
	if(*pList == ListNode(vRef)){
		std::cout << "OK" << std::endl;
	}else{
		std::cout << "NOT OK" << std::endl;
		for(int i = 0; i < n; ++i){
			vLists[i]->dump();
		}
		ListNode(vRef).dump();
	}

	
	return 0;
}



