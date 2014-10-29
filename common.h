/*
 * For leetcode common use.
 */

#ifndef __LEETCODE_COMMON_H__
#define __LEETCODE_COMMON_H__
//OS
#include <assert.h>

//C
#include <stdio.h>

//C++
#include <climits>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
#include <exception>

struct ListNode {
	int val;
	ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
    ListNode() : val(0), next(NULL) {}

public:
	void from(int A[], int m){
		int i = 0;
		ListNode* p = this;
		while(i < m){
			if(i != 0){
				p->next = new ListNode(A[i]);
				p = p->next;
			}else{
				val = A[i];
			}
			i++;
		}
	}

	void dump(){
		ListNode* p = this;
		while(NULL != p){
			std::cout << p->val << "->";
			p = p->next;
		}
		std::cout << std::endl;
	}
};

void printArray(int A[], int n, const char* pszArrayName = NULL)
{
	
	if(NULL != pszArrayName){
		printf("%s[", pszArrayName);
	}else{
		printf("Array[");
	}

	for(int i = 0; i < n; ++i)
		printf("%d,", A[i]);
	printf("]\n");
}

using std::string;
using std::vector;

#endif
