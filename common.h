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
#include <set>
#include <map>
#include <hash_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <exception>

//EXT.
#include <ext/hash_map>
using __gnu_cxx::hash_map;

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

std::vector<int> generateRandomIntVector(int size,
                                         int lower_bound,
                                         int upper_bound){
    if(size < 0 )
        return std::vector<int>();

    uint32_t seed = time(NULL);
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


using std::string;
using std::vector;
using std::set;
using std::pair;

#endif
