#include "common.h"


class Solution {
public:
	void reverseWords(string &s) {
		vector<string> vStr = splitString(s, ' ');
		s.clear();
		for (vector<string>::reverse_iterator rIt = vStr.rbegin(); rIt != vStr.rend(); ++rIt)
		{
			s += *rIt;
			s += " ";
		}
		if (s.size() > 1)
			s.resize(s.size() - 1);
	}

	vector<string> splitString(string& s, char ch){
		vector<string> vWords;
		string words(s);
		int pos1 = words.find_first_not_of(ch);
		int pos2 = words.find_first_of(ch, pos1);
		while (pos2 != string::npos && pos2 > pos1){
			string word(words.begin() + pos1, words.begin() + pos2);
			vWords.push_back(word);
			pos1 = words.find_first_not_of(ch, pos2);
			pos2 = words.find_first_of(ch, pos1);
		}
	
		if (pos2 == string::npos && pos2 != pos1){
			string word(words.begin() + pos1, words.end());
			vWords.push_back(word);
		}
		return vWords;
	}
};

int main(int argc, char** argv){
	char psz[] = "   a b  ";
	string str(psz);
	cout << str << "." << endl;
	Solution s;
	s.reverseWords(str);
	cout << str << "." << endl;
	return 0;
}