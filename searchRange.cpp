#include "common.h"

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        return searchRange(A, 0, n, target);
    }

    vector<int> searchRange(int A[], int s, int e, int target) {
        if (NULL == A || s >= e)
            return vector<int>(2, -1);

        int m = s + (e-s)/2;
        if(A[m] < target){
            return searchRange(A,  m + 1, e, target);
        }else if(A[m] > target){
            return searchRange(A, s, m, target);
        }else{ // A[m] == target
            // left
			int l = lowerBound(A + s, m - s + 1, target) + s;
			int r = upperBound(A + m, e - m, target) + m - 1;
            vector<int> vRange;
            vRange.push_back(l);
            vRange.push_back(r);
            return vRange;
        }
    }

	int lowerBound(int A[], int n, int t){
            int s = 0;
			int c = n;
			int i = 0;
            while(c > 0){
                int step = c/2;
				i = s + step;
                if(A[i] < t){
                    s = i + 1;
                    c -= step + 1;
                }else{
                    c = step;
                }
            }
            return s;
	}

	int upperBound(int A[], int n, int t){
            int s = 0;
			int c = n;
			int i = 0;
            while(c > 0){
                int step = c/2;
				i = s + step;
                if(A[i] <= t){
                    s = i + 1;
                    c -= step + 1;
                }else{
                    c = step;
                }
            }
            return s;
	}

};

int main(int argc, char** argv){

    if(argc < 3){
        printf("%s input target.\n", argv[0]);
		return 0;
	}

    Solution s;
	string strPattern(argv[1]);
	vector<int> num;
	for(int i = 0; i < strPattern.size(); ++i){
		char ch = strPattern[i];
		num.push_back(ch - '0');
	}
	printContainer<vector<int> >(num, num.size(), "Input");

    vector<int> vRange = s.searchRange((int*)&num[0], num.size(), atoi(argv[2]));
    printContainer<vector<int> >(vRange, vRange.size(), "Result");
	return 0;
}
