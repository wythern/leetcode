/*
 * For leetcode common use.
 */

#ifndef __LEETCODE_COMMON_H__
#define __LEETCODE_COMMON_H__
//OS
#ifndef _WIN32
#include <sys/time.h>
#endif
#include <assert.h>

//C
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <memory.h>
#include <string.h>

//C++
#include <climits>
#include <vector>
#include <list>
#include <queue>
#include <set>
//#include <multiset>
//#include <multimap>
#include <stack>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <ostream>
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
using std::multiset;
using std::multimap;
using std::map;
using std::unordered_map;
using std::unordered_set;
using std::bitset;
using std::pair;
using std::cout;
using std::endl;
using std::find;
using std::list;
using std::swap;
using std::queue;
using std::stack;
using std::stringstream;
using std::ostringstream;

struct ListNode {
    int val;
    ListNode *next;
	ListNode *tail;

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

		tail = p;
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

class ProfilingCout
{
public:
	ProfilingCout(){};
	~ProfilingCout(){};

public:
	void operator << (const string& str){
		cout << "TimeStamp: " << clock() << endl;
		cout << str << endl;
	}

	void operator << (const int k){
		cout << "TimeStamp: " << clock() << endl;
		ostringstream oss;
		oss << k;
		cout << oss.str() << endl;
	}

};

static ProfilingCout pfcout;

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

	TreeNode* find(int n){
		return findImpl(this, n);
	}

	TreeNode* findImpl(TreeNode* root, int n){
		if (root->val == n)
			return root;

		TreeNode* pNode = NULL;
		if (root->left){
			pNode = findImpl(root->left, n);
		}

		if (pNode == NULL && root->right){
			pNode = findImpl(root->right, n);
		}

		return pNode;
	}

private:
	bool m_bInit;
};

template<class H>
class MyHashMap {
public:
	MyHashMap() : m_nHash(32749) {
		m_vMap = vector<vector<H> >(m_nHash, vector<H>());
	}
	~MyHashMap(){
		m_vMap.clear();
	}

public:
	void insert(H& v){
		H h = v;
		int i = int(v) % m_nHash;
		m_vMap[i].insert(v);
	}

	H* find(H& k){
		int i = (int k) % m_nHash;
		set<H>::iterator it = m_vMap[i].find(k);
		if (it != m_vMap[i].end())
			return &(*it);
		else
			return NULL;
	}

private:
	vector<set<H> > m_vMap;
	uint32_t m_nHash;
};

class DirectedGraph{
public:
	class DirectedGraphNode{
	public:
		DirectedGraphNode(int id) : m_Id(id)
		{}

		~DirectedGraphNode(){
			//TBD
		}

		void AddLink(DirectedGraphNode* node){
			m_Graph.push_back(node);
		}
		friend class DirectedGraph;
	private:
		int m_Id;
		vector<DirectedGraphNode*> m_Graph;
	};

public:
	DirectedGraph(uint32_t nums, vector<pair<int, int>>& prerequisites) : m_bHasCycle(false)
	{
		for (size_t i = 0; i < nums; i++)
		{
			m_NodeIds[i] = new DirectedGraphNode(i);
		}

		for (size_t i = 0; i < prerequisites.size(); i++)
		{
			pair<int, int>& edgeUV = prerequisites[i];
			uint32_t nodeU = edgeUV.first;
			uint32_t nodeV = edgeUV.second;

			if (nodeU >= nums || nodeV >= nums)
				return;

			DirectedGraphNode* pNodeU = m_NodeIds[nodeU];
			DirectedGraphNode* pNodeV = m_NodeIds[nodeV];
			pNodeU->AddLink(pNodeV);
		}
	}
	
	~DirectedGraph(){
		for (unordered_map<int, DirectedGraphNode*>::iterator it = m_NodeIds.begin(); it != m_NodeIds.end(); ++it)
		{
			delete it->second;
		}
		m_NodeIds.clear();
	}

public:
	bool hasCycle(){
		unordered_set<DirectedGraphNode*> visited;
		unordered_set<DirectedGraphNode*> inPath;
		for (unordered_map<int, DirectedGraphNode*>::iterator it = m_NodeIds.begin();
			it != m_NodeIds.end(); ++it)
		{
			if (visited.insert(it->second).second)
				dfsImplRecursive(it->second, visited, inPath);
		}

		return m_bHasCycle;
	}

	vector<int> topologicalSort(DirectedGraph& g){
		unordered_set<DirectedGraphNode*> visited;
		unordered_set<DirectedGraphNode*> inPath;
		for (unordered_map<int, DirectedGraphNode*>::iterator it = m_NodeIds.begin();
			it != m_NodeIds.end(); ++it)
		{
			if (visited.insert(it->second).second)
				dfsImplRecursive(it->second, visited, inPath, true);
		}

		vector<int> vTopoSequence;
		while (!m_bHasCycle && !m_NodeStack.empty())
		{
			vTopoSequence.push_back(m_NodeStack.top()->m_Id);
			m_NodeStack.pop();
		}

		return vTopoSequence;
	}

	class FuncPrint{
	public:
		void operator () (DirectedGraphNode* node) const {
			cout << node->m_Id << ",";
		}
	};

	void dump(){
		unordered_set<DirectedGraphNode*> visited;
		for (unordered_map<int, DirectedGraphNode*>::iterator it = m_NodeIds.begin();
			it != m_NodeIds.end(); ++it)
		{
			if (visited.insert(it->second).second)
				bfs(it->second, visited, FuncPrint());
		}
	}

private:
	void dfsImplRecursive(DirectedGraphNode* node, unordered_set<DirectedGraphNode*>& visited, unordered_set<DirectedGraphNode*>& inPath, bool bTopoNo = false){
		if (node){
			inPath.insert(node);

			for (size_t i = 0; i < node->m_Graph.size(); i++)
			{
				if (inPath.find(node->m_Graph[i]) != inPath.end()){
					m_bHasCycle = true;
					return;
				}

				if (visited.insert(node->m_Graph[i]).second){
					dfsImplRecursive(node->m_Graph[i], visited, inPath, bTopoNo);
				}
			}
			inPath.erase(node);

			if (bTopoNo)
				m_NodeStack.push(node);
		}
	}

	void bfs(DirectedGraphNode* node, unordered_set<DirectedGraphNode*>& visited, const FuncPrint& func){
		std::list<DirectedGraphNode*> stackNode;
		stackNode.push_front(node);
		while (!stackNode.empty()){
			DirectedGraphNode* pNode = stackNode.front();
			stackNode.pop_front();
			func(pNode);

			for (int i = 0; i < (int)pNode->m_Graph.size(); ++i){
				if (visited.insert(pNode->m_Graph[i]).second){
					stackNode.push_back(pNode->m_Graph[i]);
				}
			}
		}
	}
private:
	unordered_map<int, DirectedGraphNode*> m_NodeIds;
	bool m_bHasCycle;
	stack<DirectedGraphNode*> m_NodeStack;
};


struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) { m_bInit = true; };

	//--
	UndirectedGraphNode() : m_bInit(false){}
	bool m_bInit;

	static bool isEqual(const UndirectedGraphNode* lhs, const UndirectedGraphNode* rhs){
		return false;
	}

	static UndirectedGraphNode* from(char* serializedGraph){
		/* serialize string like {0,1,2#1,2#2,2}
		 * should output a graph as:
		 *     1
		 *	 /  \
		 *	/    \
		 * 0 ----- 2
		 *	      / \
		 *	      \_/
		 */		
		map<int, UndirectedGraphNode*> setVisited;
		char* pStart = serializedGraph;
		char* pEnd = strchr(pStart, '#');
		while (pEnd != NULL){
			UndirectedGraphNode* pNode = parseOneNode(pStart, pEnd, setVisited);
			pStart = pEnd + 1;
			pEnd = strchr(pStart, '#');
		}

		UndirectedGraphNode* pNode = parseOneNode(pStart, pStart + strlen(pStart), setVisited);
		return setVisited.find(atoi(serializedGraph))->second;
	}

	static UndirectedGraphNode* parseOneNode(char* start, char* end, map<int, UndirectedGraphNode*>& setVisited){
		char* pStart = start;
		char* pEnd = strchr(start, ',');
		UndirectedGraphNode* pNode;
		int id = atoi(pStart);
		if (setVisited.find(id) == setVisited.end()){
			pNode = new UndirectedGraphNode(id);
			setVisited[id] = pNode;
		}
		else{
			pNode = setVisited.find(id)->second;
		}

		if (NULL == pEnd || end == pEnd)
			return pNode;

		pStart = pEnd + 1;
		pEnd = strchr(pStart, ',');
		UndirectedGraphNode* pSubNode;
		while (pEnd != NULL && pEnd < end){
			id = atoi(pStart);
			if (setVisited.find(id) == setVisited.end()){
				pSubNode = new UndirectedGraphNode(id);
				setVisited[id] = pSubNode;
			}
			else{
				pSubNode = setVisited.find(id)->second;
			}
			pNode->neighbors.push_back(pSubNode);
			pStart = pEnd + 1;
			pEnd = strchr(pStart, ',');
		}

		if (pStart < end){
			id = atoi(pStart);
			if (setVisited.find(id) == setVisited.end()){
				pSubNode = new UndirectedGraphNode(id);
				setVisited[id] = pSubNode;
			}
			else{
				pSubNode = setVisited.find(id)->second;
			}
			pNode->neighbors.push_back(pSubNode);
		}
		return pNode;
	}


	string serialize(){
		return serializeImpl(map<int, int>());
	}

	string serializeImpl(map<int, int>& setVisited){
		string serializeString("#");
		ostringstream ss;
		ss << label;
		for (size_t i = 0; i < neighbors.size(); i++)
		{
			ss << ',';
			ss << neighbors[i]->label;
		}
		serializeString += ss.str();

		setVisited[label] = 1;
		for (size_t i = 0; i < neighbors.size(); i++)
		{
			if (setVisited[neighbors[i]->label] != 1
				&& setVisited[neighbors[i]->label] != 2 // Not visited.
				&& !neighbors[i]->neighbors.empty())	// Have neighbour.
				serializeString += neighbors[i]->serialize();
		}

		setVisited[label] = 2;
		return serializeString;
	}

};

template <class T>
static void printArray(T A[], int n, const char* pszArrayName = NULL)
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
static void printContainer(T A, int n, const char* pszArrayName = NULL, bool bCR = false)
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

static void printArray(vector<string>& vStr, char ch = '\n'){
	for(vector<string>::iterator it = vStr.begin();
		it != vStr.end();
		++it){
		cout << *it << ch;
	}
}

static std::vector<int> generateRandomIntVector(int size,
                                         int lower_bound,
                                         int upper_bound){
    if(size < 0 )
        return std::vector<int>();

#ifndef _WIN32
	struct timeval tv;
    gettimeofday(&tv,NULL);
	uint32_t seed = tv.tv_sec + tv.tv_usec;
#else
    time_t seed = time(NULL);
	printf("seed = %d.\n", seed);
#endif
    srand((int)seed);

    double field = upper_bound - lower_bound;
    std::vector<int> v;
	for (int i = 0; i < size; ++i)
		v.push_back(int(field*rand() / RAND_MAX + lower_bound));

    return v;
}

static void* mallocNdIntArray(const int d, const int sizes[], char initVaule = 0){
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

template < class T>
static vector<vector<T> > Init2DTable(T A[], int r, int c){
	vector<vector<T> > table;
	for (int i = 0; i < r; i++)
	{
		vector<T> v(A + i * c, A + i * c + c);
		table.push_back(v);
	}
	return table;
}

static double gGlobalTimeStamp;
static double currentTiming()
{
#ifndef _WIN32
    timeval endtime;
    gettimeofday(&endtime,0);
    return 1000000*(endtime.tv_sec) + endtime.tv_usec;
#endif
    //return clock() / CLK_TCK; //start the timer
	return 0;
}

static double currentTimingMs()
{
    return currentTiming()/1000;
}

#endif

