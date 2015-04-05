#include "common.h"

class Solution {
public:
	class CharStat{
	public:
		CharStat(char ch) : key(ch)
						  , count(1)
		{}

		CharStat(char ch, int cnt) : key(ch)
								   , count(cnt)
		{}
			
		~CharStat(){vIdx.clear();}

		friend class Solution;

		bool operator < (CharStat& rhs) const{
			return key < rhs.key;
		}

		bool operator == (CharStat& rhs) const{
			return key == rhs.key;
		}

		void AddRef(){++count;};
		void DecRef(){++count;};

	private:
		char key;
		int  count;
		vector<int> vIdx;
	};
	
    string minWindow(string S, string T) {
		if(S.empty() || T.empty())
			return string("");

		string sortT(T);
		std::sort(sortT.begin(), sortT.end());
		//std::bitset<sortT.size()> status;
		vector<std::bitset<32> > status(sortT.size()/32 + 1, bitset<32>());
		vector<int> vIdx(sortT.size(), 0);
		pair<int, int> pairIdxLen(-1, INT_MAX);
		for(int i = 0; i < S.size(); ++i){
			if(sortT.find(S[i]) != string::npos){
				pair<int, int> idxLen = updateWindowStatus(sortT, status, vIdx, i, S[i]);
				if(pairIdxLen.second > idxLen.second){
					pairIdxLen = idxLen;
				}
			}
		}

		if(pairIdxLen.first != -1)
			return string(S.begin() + pairIdxLen.first, S.begin() + pairIdxLen.first + pairIdxLen.second);

		return string("");
	}

	pair<int, int> updateWindowStatus(string sortT, vector<bitset<32> >& status, vector<int>& vIdx, int idx, char ch){
		bool bInsert = false;
		int rangeS = -1;
		int rangeE = 0; //[S, E] of ch;
		for(int i = 0; i < sortT.size(); ++i){
			if(ch == sortT[i]){
				if(-1 == rangeS){
					rangeS = i;
				}
				rangeE = i;
				if(!status[i/32][i%32]){
					vIdx[i] = idx;
					status[i/32][i%32] = 1;
					bInsert = true;
				}
			}
		}

		if(!bInsert){
			vIdx[rangS] = idx;
			sort(vIdx.begin() + rangeS, vIdx.begin() + rangeE + 1);
		}

		if
		
		return pair<int, int>(-1, INT_MAX);
	}

	string minWindowNoDup(string S, string T) {
		if(S.empty() || T.empty())
			return string("");

		map<char, int> mapChIdx;
		pair<int, int> pairIdxLen(-1, INT_MAX);
		string strT = T;
		std::sort(strT.begin(), strT.end());
		strT.erase(std::unique(strT.begin(), strT.end()), strT.end());
		for(int i = 0; i < S.size(); ++i){
			if(std::find(strT.begin(), strT.end(), S[i]) != strT.end()){
				mapChIdx[S[i]] = i;
				if(mapChIdx.size() == strT.size()){
					pair<int, int> idxLen = calcMinWindow(mapChIdx);
					if(pairIdxLen.second > idxLen.second){
						pairIdxLen = idxLen;
					}
				}
			}
		}

		if(pairIdxLen.first != -1)
			return string(S.begin() + pairIdxLen.first, S.begin() + pairIdxLen.first + pairIdxLen.second);

		return string("");
	}

	std::pair<int, int> calcMinWindow(map<char, int>& mapChIdx){
		int idxMin = INT_MAX;
		int idxMax = 0;
		for(map<char, int>::iterator it = mapChIdx.begin();
			it != mapChIdx.end();
			++it){
			if(idxMin > it->second)
				idxMin = it->second;
			if(idxMax < it->second)
				idxMax = it->second;
		}
		return std::pair<int, int>(idxMin, idxMax - idxMin + 1);
	}


    string minWindowBad(string S, string T) {
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
	string S("ADOBECODEBANC");
	string T("ABC");
	if(argc >= 3){
		S = string(argv[1]);
		T = string(argv[2]);
	}
	//string S("ask_not_what_your_country_can_do_for_you_ask_what_you_can_do_for_your_country");
	//string T("ask_country");

	Solution s;
	cout << s.minWindow(S, T) << endl;
	return 0;
}
