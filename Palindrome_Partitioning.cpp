#include "common.h"

class Solution {
public:
	vector<vector<int> > m_cutTable;
	vector<vector<int> > m_accTable;
public:
	int minCut(string s) {
		if (s.empty())
			return 0;
		m_cutTable = vector<vector<int> >(s.size() + 1, vector<int>(s.size() + 1, -1));
		m_accTable = vector<vector<int> >(s.size() + 1, vector<int>(s.size() + 1, 0));
		return minCutRecursive(s, 0, s.size());
		buildupTable(s);
		return m_cutTable[0][s.size()];
	}

	void buildupTable(string& s){
		for (int i = s.size(); i >= 0; --i){
			for (int j = 0; j < s.size() + 1; ++j){
				m_cutTable[i][j] = calcValue(s, i, j);
			}
		}
	}

	int calcValue(string& s, int i, int j){
		if (j <= i)
			return -1;

		if (i == j - 1)
			return 0;

#if 1
		if (isPalindrome(string(s.begin() + i, s.begin() + j)))
			return 0;
#endif

		int minCut = INT_MAX;
		for (int k = i + 1; k < j; ++k){
			int cut = m_cutTable[i][k] + m_cutTable[k][j] + 1;
			if (minCut > cut)
				minCut = cut;
		}
		
		return minCut;
	}

	int minCutRecursive(string& s, int i, int j){
		m_accTable[i][j]++;
		if (m_cutTable[i][j] != -1)
			return m_cutTable[i][j];

		if (isPalindrome(string(s.begin() + i, s.begin() + j)))
			return 0;

		int min = INT_MAX;
		for (int k = i + 1; k < j; ++k){
			if (isPalindrome(string(s.begin() + i, s.begin() + k))){
				int cutK = 1 + minCutRecursive(s, k, j);
				if (min > cutK){
					min = cutK;
				}
			}
		}
		m_cutTable[i][j] = min;
		return min;
	}

	vector<vector<string>> partition(string s) {
		vector<vector<string>> results;
		if (s.empty())
			return results;

		for (int p = s.size() - 1; p >= 0; --p){
			string candidate = string(s.begin() + p, s.end());
			if (isPalindrome(candidate)){
				string subString = string(s.begin(), s.begin() + p);
				if (!subString.empty()){
					vector<vector<string>> subResults = partition(subString);
					for (int i = 0; i < subResults.size(); ++i)
						subResults[i].push_back(candidate);
					results.insert(results.end(), subResults.begin(), subResults.end());
				}
				else{
					vector<string> v(1, candidate);
					results.push_back(v);
				}
			}
		}
		return results;
	}

	bool isPalindrome(string& str){
		int i = 0;
		int j = str.length() - 1;
		bool bIsPalindrome = true;
		while (bIsPalindrome && i <= j){
			bIsPalindrome &= (str[i] == str[j]);
			++i; --j;
		}

		return bIsPalindrome;
	}
};

int main(int argc, char** argv){
	Solution s;
	//string str("apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp");
	string str("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	//string str("apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdf");
#if 0
	vector<vector<string>> results = s.partition(str);
	for (int i = 0; i < results.size(); ++i){
		printArray(results[i], ',');
		cout << "----" << endl;
	}
#endif;
	cout << s.minCut(str) << endl;
#if 0
	for (int i = 0; i < str.size(); ++i){
		printContainer<vector<int>>(s.m_accTable[i], str.size());
		cout << "----" << endl;
	}
#endif

	return 0;
}
