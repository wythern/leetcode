#include "common.h"

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
		vector<int> vResult;
        for(vector<int>::reverse_iterator rIt = digits.rbegin();
            rIt != digits.rend();
            ++rIt){
                int s = *rIt + carry;
				carry = s/10;
				*rIt = s%10;
            }
        
        if(carry){
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};	

int main(int argc, char** argv){
	int A[] = {9, 9};
	Solution s;
	vector<int> vA(A, A+2);
	vector<int> vB(s.plusOne(vA));
	printContainer<vector<int> >(vB, vB.size(), "vB");
	return 0;
}
