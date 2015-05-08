/*
 * For leetcode common use.
 */

#ifndef __LEETCODE_COMMON_H__
#define __LEETCODE_COMMON_H__
//OS
#include <sys/time.h>
#include <assert.h>

//C
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <memory.h>

//C++
#include <climits>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
#include <bitset>
#include <exception>
//#include <hash_map>

//EXT.
//#include <ext/hash_map>
//using __gnu_cxx::hash_map;
using std::string;
using std::vector;
using std::set;
using std::map;
using std::bitset;
using std::pair;
using std::cout;
using std::endl;
using std::find;
using std::list;
using std::swap;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
	ListNode(int A[], int m){from(A, m);}
	ListNode(vector<int> vA) {from(&vA[0], vA.size());}
    ListNode() : val(0), next(NULL) {}

public:
    void from(int A[], int m){
		val = INT_MIN;
		next = NULL;

		int i = 0;
        ListNode* p = this;
        while(i < m){
            if(i != 0){
                p->next = new ListNode(A[i]);
                p = p->next;
            }else{
                val = A[i];
				next = NULL;
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

	const bool operator == (const ListNode& rhs) const{
		bool ret = true;
		const ListNode* plhs = this;
		const ListNode* prhs = &rhs;
		while(NULL != plhs &&
			  NULL != prhs &&
			  plhs->val == prhs->val){
			plhs = plhs->next;
			prhs = prhs->next;
		}

		return ((plhs == NULL) && (prhs == NULL));
	}

};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
	TreeNode(int A[], int n) : left(NULL)
							 , right(NULL)
							 , m_bInit(false)
	{from(A, n);}

    TreeNode(int x) : val(x), left(NULL), right(NULL), m_bInit(false) {}
	~TreeNode() {
		if(left){delete left; left = NULL;}
		if(right){delete right; right = NULL;}
	}

public:
	/* parse array like: [1, #, 2, 3].
	 *       1
	 *      / \
	 *	  ()   2
	 *        /
	 *       3											\
	 */
	void from(int A[], int n){
		if(A == NULL || 0 == n)
			return;

		if(A[0] == '#')
			return;

		m_bInit = true;
		val = A[0];
		list<TreeNode*> listNode;
		listNode.push_front(this);
		int i = 0;
		while(i < n && !listNode.empty()){
			TreeNode* p = listNode.front();
			listNode.pop_front();
			if(i + 1 < n && A[i+1] != '#') {
				p->left = new TreeNode(A[i+1]);
				listNode.push_back(p->left);
			}
			if(i + 2 < n && A[i+2] != '#') {
				p->right = new TreeNode(A[i+2]);
				listNode.push_back(p->right);
			}
			i += 2;
		}
	}

	void dump(){
#if 0
		list<TreeNode*> v(1, this);
		cout << '[';
		while(!v.empty()){
			TreeNode* p = v.front();
			v.pop_front();
			if(p){
				cout << p->val << ",";
				if(p->left) v.push_back(p->left);
				if(p->right) v.push_back(p->right);
			}
		}
		cout << ']' << endl;
#endif
		cout << '[';
        dump(this);        
		cout << ']' << endl;
	}

    void dump(TreeNode* root){
        if(!root) return;
        dump(root->left);
        cout << root->val << ",";
        dump(root->right);
    }

	bool isValid(){return m_bInit;}

private:
	bool m_bInit;
};

template <class T>
void printArray(T A[], int n, const char* pszArrayName = NULL)
{

    if(NULL != pszArrayName){
        printf("%s[", pszArrayName);
    }else{
        printf("Array[");
    }

    for(int i = 0; i < n; ++i)
		std::cout << A[i] << ",";
    printf("]\n");
}

template <class T>
void printContainer(T A, int n, const char* pszArrayName = NULL, bool bCR = false)
{
    if(NULL != pszArrayName){
        printf("%s[", pszArrayName);
    }else{
        printf("Array[");
    }

    for(typename T::iterator i = A.begin(); i != A.end(); ++i){
		std::cout << *i << ",";
		if(bCR)
			cout << endl;
	}
    printf("]\n");
}

void printArray(vector<string>& vStr){
	for(vector<string>::iterator it = vStr.begin();
		it != vStr.end();
		++it){
		cout << *it << endl;
	}
}

std::vector<int> generateRandomIntVector(int size,
                                         int lower_bound,
                                         int upper_bound){
    if(size < 0 )
        return std::vector<int>();

#if 1
	struct timeval tv;
    gettimeofday(&tv,NULL);
	uint32_t seed = tv.tv_sec + tv.tv_usec;
#else
	time_t stime;
    uint32_t seed = time(NULL);
	printf("seed = %d.\n", seed);
#endif
    srand(seed);

    double field = upper_bound - lower_bound;
    std::vector<int> v;
    for(int i = 0; i < size; ++i)
        v.push_back(field*rand()/RAND_MAX + lower_bound);

    return v;
}

void* mallocNdIntArray(const int d, const int sizes[], char initVaule = 0){
    void* p = NULL;
    if(0 >= d)
        return p;

    if(1 == d){
        p = (void*)malloc(sizes[0]*sizeof(int));//sizeof(type)?
        memset(p, initVaule, sizes[0]*sizeof(int));
    }
    else{
        int** array = (int**)malloc(sizes[0]*sizeof(int*));
        for(int i = 0; i < sizes[0]; ++i) {
            array[i] = (int*)mallocNdIntArray(d-1, sizes+1);
        }
        p = (void*)array;
    }

    return p;
}

double gGlobalTimeStamp;
double currentTiming()
{
    timeval endtime;
    gettimeofday(&endtime,0);
    return 1000000*(endtime.tv_sec) + endtime.tv_usec;
    //return clock() / CLK_TCK; //start the timer
}

double currentTimingMs()
{
    return currentTiming()/1000;
}

#endif

