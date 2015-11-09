#include "common.h"

class Solution {
public:
	string convertToTitle(int n) {
		string strTitle;
		const char* letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

		while (n){
			strTitle += letters[(n - 1) % 26 ];
			n = (n - 1)/26;
		}
		return string(strTitle.rbegin(), strTitle.rend());
	}
};

int main(int argc, char** argv){
	Solution s;
	for (int i = 1; i < 100; ++i){
		cout << s.convertToTitle(i) << endl;
	}
	return 0;
}