#include "common.h"

using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		std::string strUniqueString = LongestSubUniqueString(s);
		return strUniqueString.length();
    }

	std::string LongestSubUniqueString(std::string& s){
		int pos;
		std::string strUnique;
		std::string strResult;
		int startPos = 0;
		for(pos = 0; pos < s.length(); ++pos){
			int dupPos = strUnique.find(s[pos]);
			if(dupPos == std::string::npos){
				// Unique character.
				strUnique += s[pos];
				if(pos == s.length() - 1)
					if(strUnique.length() > strResult.length())
						strResult = strUnique;
			}else{
				if(strUnique.length() > strResult.length())
					strResult = strUnique;

				startPos = startPos + dupPos + 1;
				int newLength = pos - startPos + 1;
				strUnique = std::string(s, startPos, newLength);
			}
		}

		return strResult;
	}
};


int main(int argc, char** argv)
{
	Solution s;
	std::string strInput("qopubjguxhxdipfzwswybgfylqvjzhar");
	//std::cin >> strInput;
	std::string strResult = s.LongestSubUniqueString(strInput);

	std::cout << strResult << std::endl;
	return 0;
}
