#include "common.h"

class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		return removeInvalidParenthesesDFS(s);
	}

	vector<string> removeInvalidParenthesesDFS(string& s){
		vector<string> vResultStrings;

		list<string> strList;
		strList.push_back(s);

		bool bFound = false;
		list<string> strNextList;
		set<string> strVisited;
		while (!strList.empty())
		{
			string strCandidate = strList.front();
			strList.pop_front();

			if (isValidParenthese(strCandidate)){
				bFound = true;
				vResultStrings.push_back(strCandidate);
			}

			for (size_t i = 0; i < strCandidate.size(); i++)
			{
				if (strCandidate[i] == '(' || strCandidate[i] == ')'){
					string strNew = strCandidate.substr(0, i) + strCandidate.substr(i + 1, strCandidate.size() - i - 1);
					if(strVisited.insert(strNew).second)
						strNextList.push_back(strNew);
				}
			}

			if (!bFound && strList.empty()){
				swap(strList, strNextList);
				strVisited.clear();
			}
		}

		vResultStrings.erase(std::unique(vResultStrings.begin(), vResultStrings.end()), vResultStrings.end());
		return vResultStrings;
	}

	bool isValidParenthese(string& s){
		int left = 0;
		int right = 0;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				++left;
			else if (s[i] == ')'){
				if (left)
					--left;
				else
					++right;
			}
		}
		return !(left || right);
	}
};

int main(int argc, char** argv){
	Solution s;
	const char* p = "()(((((((()";
	string str(p, p + strlen(p));
	vector<string>& vStr(s.removeInvalidParentheses(str));

	printContainer<vector<string>>(vStr, vStr.size());
	return 0;
}


