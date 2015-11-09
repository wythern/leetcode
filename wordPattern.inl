#include "common.h"


class Solution {
public:
	bool wordPattern(string pattern, string str) {
		vector<string> strArray = splitString(str);
		map<char, string> patternMap;
		map<string, char> strMap;

		if (pattern.size() != strArray.size())
			return false;

		for (int i = 0; i < pattern.size(); ++i){
			map<char, string>::iterator it = patternMap.find(pattern[i]);
			map<string, char>::iterator itS = strMap.find(strArray[i]);
			if ((it != patternMap.end() && it->second != strArray[i]) ||
				(itS != strMap.end() && itS->second != pattern[i]))
				return false;

			patternMap[pattern[i]] = strArray[i];
			strMap[strArray[i]] = pattern[i];
		}

		return true;
	}

	vector<string> splitString(string& str){
		vector<string> vecString;
		int posBegin = str.find_first_not_of(' ');
		int posEnd = posBegin;
		while (posBegin != string::npos){
			posEnd = str.find_first_of(' ', posBegin);
			vecString.push_back(str.substr(posBegin, posEnd - posBegin));
			if (posEnd == string::npos)
				break;
			posBegin = str.find_first_not_of(' ', posEnd + 1);
		}

		return vecString;
	}
};

int main(int argc, char** argv){
	Solution s;
	string str("aaa bbb ccc bbb ccc");
	string strPattern("abcbc");
	vector<string> vecStr = s.splitString(str);

	printContainer<vector<string> >(vecStr, vecStr.size());

	cout << (s.wordPattern(strPattern, str) ? "TRUE" : "FALSE") << endl;

	return 0;
}
