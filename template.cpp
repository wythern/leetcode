#include "common.h"

class Solution {
public:

};

int main(int argc, char** argv){
	char* p[] = {"1234", "12345", "4312", "61234", "53421", "1"};
	Solution s;
	vector<string> strs;
	for(int i = 0; i < sizeof(p); ++i){
		strs.insert(string(p[i]));
	}
	vector<string> vR = s.anagrams(strs);
	printContainer<vector<string> >(vResults, vResults.size(), "Result");
	return 0;
}
