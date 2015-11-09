#include "common.h"

using std::string;

class Solution {
public:
	string convert(string s, int nRows) {
		if(1 == nRows)
			return s;

		std::vector<int> vIndex(nRows, 0);
		std::string strResult;
		int nPeriod = 2*nRows - 2;
		std::string::iterator it;
		for(int i = 0; i < nRows; ++i){
			if (0 == i){
				it = s.begin();
				while (it < s.end()){
					//std::cout << *it;
					strResult += *it;
					it += nPeriod;
				}
				//std::cout << std::endl;
			}else if (nRows - 1 == i){
				it = s.begin() + nRows - 1;
				while (it < s.end()){
					//std::cout << *it;
					strResult += *it;
					it += nPeriod;
				}
				//std::cout << std::endl;
			}else{
				it = s.begin();
				std::string::iterator itLeft = it + i;
				std::string::iterator itRight = it + nPeriod - i;
				while (it < s.end()){				
					itLeft = it + i;
					itRight = it + nPeriod - i;
					//std::cout << *itLeft << *itRight;
					if(itLeft < s.end())
						strResult += *itLeft;
					if(itRight < s.end())
						strResult += *itRight;
					it += nPeriod;
				}
				//std::cout << std::endl;
			}
		}
		//std::cout << std::endl;
		return strResult;
	}

    string convert2(string s, int nRows) {
		if(1 == nRows)
			return s;

		std::vector<std::string> vString(nRows);
		std::vector<int> vIndex(nRows, 0);
		int idx = 0;
		int steps[] = {-1, 1};
		int step = 1;
		for(std::string::iterator it = s.begin();
			it < s.end();
			++it){
			vString[idx].push_back(*it);
			if(idx == 0){
				step = steps[1];
			}else if(idx == nRows - 1){
				step = steps[0];
			}
			idx += step;
		}

		std::string strResult("");
		for(std::vector<std::string>::iterator it = vString.begin();
			it < vString.end();
			++it){
			std::cout << *it << std::endl;
			strResult += *it;
		}

		return strResult;
    }
};


int main(int argc, char** argv)
{
	Solution s;
	//std::string strInput("twckwuyvbihajbmhmodminftgpdcbquupwflqfiunpuwtigfwjtgzzcfofjpydjnzqysvgmiyifrrlwpwpyvqadefmvfshsrxsltbxbziiqbvosufqpwsucyjyfbhauesgzvfdwnloojejdkzugsrksakzbrzxwudxpjaoyocpxhycrxwzrpllpwlsnkqlevjwejkfxmuwvsyopxpjmbuexfwksoywkhsqqevqtpoohpd");
	std::string strInput("PAHNAPLSIIGYIR");
	//std::cin >> strInput;
	int n = 3;
	if(argc == 3){
		strInput = std::string(argv[1]);
		n = atoi(argv[2]);
	}

	std::string strResult = s.convert(strInput, n);
	std::cout << strResult << std::endl;
	return 0;
}
