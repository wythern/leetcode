#include "common.h"

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
		map<string, vector<string> > mapAnagrams;
		vector<string> vAnagrams;
		for(vector<string>::iterator it = strs.begin();
			it != strs.end();
			++it){
			string strCandidate(*it);
			std::sort(strCandidate.begin(), strCandidate.end());
			map<string, vector<string> >::iterator itMap = mapAnagrams.find(strCandidate);
			if(itMap != mapAnagrams.end()){
				itMap->second.push_back(*it);
			}else{
				mapAnagrams[strCandidate] = vector<string>(1, *it);
			}
		}

		for(map<string, vector<string> >::iterator itMap = mapAnagrams.begin();
			itMap != mapAnagrams.end();
			++itMap){
			if(itMap->second.size() > 1){
				vAnagrams.insert(vAnagrams.end(), itMap->second.begin(), itMap->second.end());
			}
		}
		
		return vAnagrams;
    }
};

int main(int argc, char** argv){
	const char* p[] = {"1234", "12345", "4312", "61234", "53421", "1"};
	Solution s;
	vector<string> strs;
	for(int i = 0; i < sizeof(p)/sizeof(p[0]); ++i){
		strs.push_back(string(p[i]));
	}
	vector<string> vResults = s.anagrams(strs);
	printContainer<vector<string> >(vResults, vResults.size(), "Result");
	return 0;
}





