#include "common.h"

class Solution{
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		return wordBreak_DP(s, 0, s.size(), wordDict);
	}

	bool wordBreak_DP(string& s, int b, int e, unordered_set<string>& wordDict) {
		static vector<vector<int>> memory(s.size() + 1, vector<int>(s.size() + 1, -1));

		if (b >= e)
			return true;

		if (memory[b][e] != -1)
			return (memory[b][e] > 0);

		if (wordDict.find(s.substr(b, e - b)) != wordDict.end()){
			memory[b][e] = 1;
			return true;
		}

		for (size_t k = b + 1; k < e; k++)
		{
			if ((memory[b][k] != -1) || (wordDict.find(s.substr(b, k - b)) != wordDict.end())){
				memory[b][k] = 1;
				if (wordBreak_DP(s, b, k, wordDict) && wordBreak_DP(s, k, e, wordDict)){
					memory[b][e] = 1;
					return true;
				}
			}
		}

		memory[b][e] = 0;
		return false;
	}

	bool wordBreak_BF(string s, unordered_set<string>& wordDict) {
		static unordered_map<string, bool> memory;
		if (s.empty())
			return true;

		if (memory.find(s) != memory.end())
			return memory[s];

		for (int pos = 1; pos < s.size() + 1; ++pos){
			if (wordDict.find(s.substr(0, pos)) != wordDict.end()){
				if (wordBreak(s.substr(pos, s.size()), wordDict)){
					memory[s] = true;
					return true;
				}
			}
		}

		memory[s] = false;
		return false;
	}
};

int main(int argc, char** argv){
	Solution s;
	string s1("abcd");
	unordered_set<string> wordDict;

	wordDict.insert("a");
	wordDict.insert("abc");
	wordDict.insert("b");
	wordDict.insert("cd");
	pfcout << (s.wordBreak(s1, wordDict) ? "TRUE" : "FALSE");
	pfcout << (s.wordBreak_BF(s1, wordDict) ? "TRUE" : "FALSE");
	pfcout << "--------------------------------------------";
	return 0;
}
