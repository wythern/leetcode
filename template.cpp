#include "common.h"

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
		map<string, string> mapAnagrams;
		set<string> vAnagrams;
		for(vector<string>::iterator it = strs.begin();
			it != strs.end();
			++it){
			string strCandidate(*it);
			std::sort(strCandidate.begin(), strCandidate.end());
			map<string, string>::iterator itMap = mapAnagrams.find(strCandidate);
			if(itMap != mapAnagrams.end()){
				vAnagrams.push_back(itMap->second);
				vAnagrams.push_back(*it);
			}
		}
		
		return vAnagrams;
    }
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
