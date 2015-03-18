#include "common.h"

class Solution {
public:
    string addBinary(string a, string b) {
		int carry = 0;
		if (a.size() < b.size())
			std::swap(a, b);

		string::reverse_iterator rItA = a.rbegin();
		string::reverse_iterator rItB = b.rbegin();
		while(rItB != b.rend()){
			int s = (*rItA - '0') + (*rItB - '0') + carry;
			carry = s/2 + '0';
			*rItA = s%2 + '0';
			++rItA;
			++rItB;
		}

		while(rItA != a.rend()){
			int s = (*rItA - '0') + carry;
			carry = s/2 + '0';
			*rItA = s%2 + '0';
			++rItA;
		}

		if(carry)
			a.insert(a.begin(), '1');

		return a;
    }
};

int main(int argc, char** argv){
	char A[] = "11";
	char B[] = "111";
	string sA(A, A+2);
	string sB(B, B+3);
	Solution s;
	cout << s.addBinary(sA, sB) << endl;
	return 0;
}
