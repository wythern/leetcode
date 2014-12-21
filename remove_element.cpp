#include "common.h"

class Solution {
public:

	int removeElement(int A[], int n, int elem) {
		if(NULL == A || 0 == n)
			return 0;

		int elemPos = 0;
		int pos = 0;
		int length = 0;
		while(pos < n){
			if(A[pos] == elem){
				if(elemPos != pos)
					std::swap(A[pos], A[elemPos]);

				++elemPos;
			}
			++pos;
		}

		if(elemPos != 0)
			memmove(A, A + elemPos, (n - elemPos)*sizeof(int));

		return n - elemPos;
	}

    int removeElement_unfinish(int A[], int n, int elem) {
		if(NULL == A || 0 == n)
			return 0;
		
		int pos = 0;
		int length = 0;
		while(pos < n){
			if(A[pos] == elem){
				int place = pos + 1;
				while(place < n && A[place] == elem){
					++place;
				}

				// if next is not elem
				if(place != pos + 1){
					std::swap(A[pos], A[place - 1]);
					length = pos + 1;
					pos = place - 1;
				}else{ // next is elem
					// find next non-elem.
					while(place < n && A[place] != elem){
						++place;
					}
					// then, find next elem
					while(place < n && A[place] == elem){
						++place;
					}

					if(place != n || A[place] != elem){
						std::swap(A[pos], A[place - 1]);
						length = pos + 1;
					}
					++pos;
				}
			}else{
				++pos;
				length = pos + 1;
			}
		}

		return length;
    }
};

int main(int argc, char** argv){
	Solution s;
	int n = 10;
	int r = 5;
	if(argc > 1){
		n = atoi(argv[1]);
		r = atoi(argv[2]);
	}

	vector<int> vInts(generateRandomIntVector(n, 1, n));
	int* pA = (int*)malloc(vInts.size() * sizeof(int));
	for(int i = 0; i < vInts.size(); ++i)
		pA[i] = vInts[i];

	std::sort(vInts.begin(), vInts.end());
	printArray(pA, vInts.size(), "A+r");
	printArray(&vInts[0], vInts.size(), "sorted A+r");
	std::cin >> r;
	int k = s.removeElement(pA, n, r);
	printArray(pA, k, "A-r");
	vector<int> vNewInts(pA, pA+k);
	std::sort(vNewInts.begin(), vNewInts.end());
	printArray(&vNewInts[0], vNewInts.size(), "sorted A-r");
	return 0;
}

