#include "common.h"

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		if (s.empty() || words.empty() || words[0].empty())
			return vector<int>();

		//build hash table.
		unordered_map<string, int> wordsHash;
		int uniqueWords = 0;
		for (size_t i = 0; i < words.size(); i++)
		{
			string v = words[i];
			if (wordsHash.find(v) != wordsHash.end())
				wordsHash[v]++;
			else{
				wordsHash[v] = 1;
				uniqueWords++;
			}
		}
		
		int window = words[0].size();
		int pos = 0;
		vector<int> vIdx;
		unordered_map<string, int> wordsHashSave(wordsHash);
		int uniqueWordsSave = uniqueWords;
		while (pos + window <= s.size()){
			int posSave = pos;
			wordsHash = wordsHashSave;
			uniqueWords = uniqueWordsSave;
			while (pos + window <= s.size()){
				unordered_map<string, int>::iterator itMap = wordsHash.find(string(s.begin() + pos, s.begin() + pos + window));
				if (itMap == wordsHash.end()){
					pos = posSave;
					++pos;
					break;
				}

				if (itMap->second - 1 < 0){
					pos = posSave;
					++pos;
					break;
				}

				--itMap->second;
				if (itMap->second == 0)
					--uniqueWords;

				if (uniqueWords == 0){
					vIdx.push_back(posSave);
					pos = posSave;
					++pos;
					break;
				}
				pos += window;
			}
		}

		return vIdx;
	}

	//useless for too much possible digits.
	uint64_t calcStringValue(string& s){
		uint64_t v = 0;
		for (size_t i = 0; i < s.size(); i++)
		{
			v <<= 7;
			v += s[i];
		}
		return v;
	}
};


int main(int argc, char** argv){
	Solution s;
	string str("wordgoodgoodgoodbestword");
	char *p[] = { "word", "good", "best", "good" };
	vector<string> words;
	for (size_t i = 0; i < sizeof(p)/sizeof(char*); i++)
	{
		words.push_back(p[i]);
	}
	vector<int> vIdx = s.findSubstring(str, words);
	printContainer<vector<int>>(vIdx, vIdx.size());
	return 0;
}


