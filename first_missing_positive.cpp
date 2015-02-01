#include "common.h"

class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		if (0 == n) {
			return 1;
		}
		vector<bool> existed(n, false);
		unsigned int i = 0;
		for (i=0; i<n; ++i) {//    scan the array A[], mark existed[k-1] vector if integer k contained in the A
			if (A[i]>0) {
				existed[A[i] - 1] = true;
			}
		}

		for (i=0; i<n; ++i) {//    scan the existed vector from 0 to n-1, break untill existed[i] === false;
			if (!existed[i]) {
				break;
			}
		}
		return i+1;
	}

    int firstMissingPositive1(int A[], int n) {
		double entry = currentTimingMs();
		if(NULL == A || 0 == n)
			return -1;

		double start = currentTimingMs();
		int min = INT_MAX;
		int next = INT_MAX;
		my_hash_map<int, int> hashMap(31, n);
		cout << "Init hash uses " << currentTimingMs() - start << " ms." << endl;
		start = currentTimingMs();
		for(int i = 0; i < n; ++i){
			if(A[i] > 0)
				hashMap[A[i]] = A[i];
		}
		cout << "build hash uses " << currentTimingMs() - start << " ms." << endl;
		start = currentTimingMs();
		int r = n;
		for(int i = 1; i < n; ++i){
			if (hashMap.find(i) == -1){
				r = i;
				break;
			}
		}
		cout << "query hash uses " << currentTimingMs() - start << " ms." << endl;
		cout << "function uses " << currentTimingMs() - entry << " ms." << endl;
		return r;
    }

	template <class T1, class T2>
	class my_hash_map {
	public:
		typedef struct node* nodeptr;
		typedef struct node{
			T1 t1;
			T2 t2;
			//nodeptr next; // using vector<node>, so this ptr is useless.
		} NODE, *NODEPTR;
		
	public:
		my_hash_map() : MULT(31)
					  , NHASH(29989)
					  , m_vTable(NHASH, vector<NODE>())
		{
		}

		my_hash_map(int mult, int hashCode) : MULT(mult)
											, NHASH(hashCode)
											, m_vTable(NHASH, vector<NODE>())
		{
		}

		~my_hash_map()
		{}

		int find(T1 t){
			if(!m_vTable[hash(t)].empty())
				return hash(t);
			else
				return -1;
		}

		T2& operator [] (T1 t1){
			vector<node>& vNode = m_vTable[hash(t1)];
			typename vector<node>::iterator it = vNode.begin();
			for(; it != vNode.end(); ++it){
				if(it->t1 == t1){
					return it->t2;
				}
			}

			NODEPTR pNode = new node;
			pNode->t1 = t1;
			vNode.push_back(*pNode);
			return pNode->t2;
		}

	private:
		uint32_t hash(T1 t1){
			return abs(t1) % NHASH;
		}

	private:
		const int MULT;// = 31;
		const int NHASH;// = 29989;
		vector<vector<NODE> > m_vTable;
	};
};

int main(int argc, char** argv){
	int A[] = {98,93,95,10,91,4,90,88,56,84,65,62,83,80,78,60,73,77,76,29,63,12,57,17,69,68,50,11,31,33,8,42,38,7,0,37,48,26,20,44,46,43,52,51,47,18,49,58,2,39,30,81,22,55,36,40,15,27,21,32,64,41,53,19,28,24,9,25,3,59,66,82,61,70,23,34,71,54,74,-1,1,45,14,79,5,35,13,72,75,85,87,6,16,86,67,89,94,92,96,97,99};
	//	int A[] = {0, 1, 5, 4, 3};
	Solution s;
	double stime = currentTimingMs();
	int r = s.firstMissingPositive(A, sizeof(A)/sizeof(A[0]));
	double etime = currentTimingMs();
	cout << "my result = " << r << ",cost " << etime - stime << " ms" << endl;

	vector<int> v(A, A+sizeof(A)/sizeof(A[0]));
	cout << "v.size() = " << v.size() << endl;
	sort(v.begin(), v.end());
	vector<int>::iterator it = find(v.begin(), v.end(), 0);
	if(it != v.end()){
		while(it + 1 != v.end()){
			if(*it + 1 != *(it + 1)){
				cout << *it + 1 << endl;
				return 0;
			}
			++it;
		}
		cout << *it + 1 << endl;
	}else{
		cout << "0" << endl;
	}

	return 0;
}
