#include "common.h"

class Solution {
	// compartor could be act as [](int a, int b){ return to_string(a) + to_string(b) > to_string(b) + to_string(a).
	// Think about it!!!!!!!!
	// But anyway, you still get AC!.
public:
	string largestNumber(vector<int>& nums) {
		vector<string> strNums;
		for (int i = 0; i < nums.size(); ++i){
			stringstream ss;
			ss << nums[i];
			strNums.push_back(ss.str());
		}

		string strLargestNum;
		largestNumberImpl(strNums, strLargestNum);
		removeHeadZeros(strLargestNum);
		return strLargestNum;
	}

	void removeHeadZeros(string& str){
		int i = 0;
		for (; i < str.size(); ++i){
			if (str[i] != '0')
				break;
		}
		i = (i == str.size()) ? i - 1 : i;
		string newStr(str.begin() + i, str.end());
		std::swap(str, newStr);
	}

	void largestNumberImpl(vector<string>& strNums, string& output){
		if (strNums.size() == 1){
			output += strNums[0];
			return;
		}

		vector<string>::iterator rRegionEnd = strNums.end();
		vector<string>::iterator rIt = strNums.begin();
		vector<string>::iterator rMaxElem = strNums.begin();
		while (++rIt != rRegionEnd)
		{
			if (lessEqual(*rMaxElem, *rIt)){
				rMaxElem = rIt;
			}
		}

		output += *rMaxElem;
		strNums.erase(rMaxElem);
		
		return largestNumberImpl(strNums, output);
	}

	bool lessEqual(string& strLhs, string& strRhs){
		int i = 0;
		int j = 0;
		while (i < strLhs.size() || j < strRhs.size()){
			if (strLhs[i] < strRhs[j]){
				return true;
			} else if (strLhs[i] > strRhs[j]){
				return false;
			} else{
				if (i == strLhs.size() - 1 && j == strRhs.size() - 1)
					break;

				++i;
				++j;
				if (i == strLhs.size())
					i = 0;
				if (j == strRhs.size())
					j = 0;
			}
		}
		return true;
	}
};


int main(int argc, char** argv){
	Solution s;
	//int A[] = {5, 51, 552, 57, 558};
	int A[] = {824, 938, 1399, 5607, 6973, 5703, 9609, 4398, 8247};
	//int A[] = { 3, 30, 34, 5, 9 };
	vector<int> vA(A, A + sizeof(A) / sizeof(int));
	cout << s.largestNumber(vA) << endl;
	return 0;
}