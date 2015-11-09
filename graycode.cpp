#include "common.h"
class Solution {
public:

	vector<int> grayCode(int n) {
		vector<int> v(1, 0);
		return v;
	}

    vector<int> grayCode1(int n) {
		vector<int> v;
		if(n == 0){
			v.push_back(0);
			return v;
		}

		if(n == 1){
			v.push_back(0);
			v.push_back(1);
			return v;
		}

		vector<int> vSubGray(grayCode1(n - 1));
		for(vector<int>::iterator it = vSubGray.begin();
			it != vSubGray.end();
			++it){
			v.push_back(*it);
		}

		for(vector<int>::reverse_iterator it = vSubGray.rbegin();
			it != vSubGray.rend();
			++it){
			v.push_back(*it | (1 << (n - 1)));
		}

		return v;
    }
};

int main(int argc, char** argv){
	Solution s;
	vector<int> A(s.grayCode1(2));
	printContainer<vector<int> >(A, A.size(), "A");
	return 0;
}
