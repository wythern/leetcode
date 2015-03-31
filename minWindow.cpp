#include "common.h"

class Solution {
public:
    string minWindow(string S, string T) {
		if(S.empty() || T.empty())
			return string("");

		map<char, vector<int> > mapChIdx;
		string strT = T;
		std::sort(strT.begin(), strT.end());
		strT.erase(std::unique(strT.begin(), strT.end()), strT.end());
		for(int i = 0; i < S.size(); ++i){
			if(std::find(strT.begin(), strT.end(), S[i]) != strT.end()){
				mapChIdx[S[i]].push_back(i);
			}
		}

		if(mapChIdx.size() != strT.size())
			return string("");

		vector<int> vIdx;
		m_pairWindow = std::pair<int, int>(0, S.size());
		getMinWindow(mapChIdx, mapChIdx.begin(), vIdx);
		return string(S.begin() + m_pairWindow.first, S.begin() + m_pairWindow.first + m_pairWindow.second);
    }

	bool getMinWindow(map<char, vector<int> >& mapChIdx,
					  map<char, vector<int> >::iterator pos,
					  vector<int>& vIdx){
		if(pos == mapChIdx.end()){
			vector<int> vSortIdx = vIdx;
			sort(vSortIdx.begin(), vSortIdx.end());
			printContainer<>(vSortIdx, vSortIdx.size(), "vIdx");
			if((vSortIdx.back() - vSortIdx.front() + 1) < m_pairWindow.second){
				m_pairWindow.first = vSortIdx.front();
				m_pairWindow.second = (vSortIdx.back() - vSortIdx.front() + 1);
				cout << "[" << m_pairWindow.first << ", " << m_pairWindow.second << "]" << endl;
			}
			return true;
		}

		map<char, vector<int> >::iterator nextPos = pos;
		nextPos++;
		for(vector<int>::iterator it = pos->second.begin();
			it != pos->second.end(); ++it){
			vIdx.push_back(*it);
			getMinWindow(mapChIdx, nextPos, vIdx);
			vIdx.pop_back();
		}
		return true;
	}
private:
	std::pair<int, int> m_pairWindow;
};

int main(int argc, char** argv){
	string S("ask_not_what_your_country_can_do_for_you_ask_what_you_can_do_for_your_country");
	string T("ask_country");

	Solution s;
	cout << s.minWindow(S, T) << endl;
	return 0;
}
