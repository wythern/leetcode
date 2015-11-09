#include "common.h"

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		// s1[0...i], s2[0...j] interleaves the s3[0...k]
		// then, test isInterleave(s1[i+1...], s2[j+1...], s3[k+1...]
		//return isInterleaveImpl(s1, 0, s1.size(), s2, 0, s2.size(), s3, 0, s3.size());
		if (s1.size() + s2.size() != s3.size())
			return false;

		if (s3.empty())
			return true;

		return isInterleaveImpl_DP(s1, s2, s3);
	}

	bool isInterleaveImpl_DP(string& s1, string& s2, string s3){
		char memory[256][256];
		memset(memory, 0, 256 * 256);

		//init the 1st line;
		for (size_t j = 0; j < s2.size(); j++)
		{
			memory[0][j + 1] = (s3[j] == s2[j]);
			if (!memory[0][j + 1])
				break;
		}

		for (size_t i = 0; i < s1.size(); i++)
		{
			memory[i + 1][0] = ((i == 0 || memory[i][0]) ? (s3[i] == s1[i]) : 0);
			for (size_t j = 0; j < s2.size(); j++)
			{
				memory[i + 1][j + 1] = ((memory[i][j + 1] ? s3[i + j + 1] == s1[i] : 0) + (memory[i + 1][j] ? s3[i + j + 1] == s2[j] : 0)) > 0;
			}
		}

		return memory[s1.size()][s2.size()] > 0;
	}



	bool isInterleaveImpl_BF(string& s1, int s1s, int s1e,
						string& s2, int s2s, int s2e,
						string& s3, int s3s, int s3e){
		if (s1s > s1e || s2s > s2e || s3s > s3e)
			return false;

		if (s3e - s3s != s1e - s1s + s2e - s2s)
			return false;

		if ((s1s == s1e || s2s == s2e)){
			string ss1(s1.c_str() + s1s, s1e - s1s);
			string ss2(s2.c_str() + s2s, s2e - s2s);
			string ss3(s3.c_str() + s3s, s3e - s3s);
			return ss1 + ss2 == ss3;
		}

		for (size_t i = s1s; i <= s1e ; i++)
		{
			for (size_t j = s2s; j <= s2e; j++)
			{
				//for (size_t k = i + j; k < s3e; k++)
				int k = i + j;
				{
					//TODO: refine the memory search and then optimize to DP.

					if ((i != s1s || j != s2s) && (i != s1e || j != s2e)){
						bool bLeft = isInterleaveImpl_BF(s1, s1s, i, s2, s2s, j, s3, s3s, k);
						bool bRight = isInterleaveImpl_BF(s1, i, s1e, s2, j, s2e, s3, k, s3e);
						
						if (bLeft && bRight)
							return true;
					}
				}
			}
		}

		return false;
	}

	char m_memory[256][256];
};

int main(int argc, char** argv){
	Solution s;
	string s1("b");
	string s2("");
	string s3("b");
	cout << (s.isInterleave(s1, s2, s3) ? "TRUE" : "FALSE") << endl;
	return 0;
}