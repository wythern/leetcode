#include "common.h"

class Solution {
public:
	int numDistinct(string s, string t) {
		return numDistinctImpl(0, s.size(), s, 0, t.size(), t);
	}

	int numDistinctImpl(int sS, int sE, string& s, int tS, int tE, string& t){
		if (tE <= tS)
			return 1;

		if (sE - sS < tE - tS)
			return 0;

		if (sE - sS == tE - tS)
			return string(s.begin() + sS, s.begin() + sE) == string(t.begin() + tS, t.begin() + tE);

		int num = 0;
		for (size_t i = sS; i < sE; i++)
		{
			//for (size_t j = tS; j < tE; j++)
			int j = tS;
			{
				if (s[i] == t[j])
					num += numDistinctImpl(i + 1, sE, s, j + 1, tE, t);
			}
		}

		return num;
	}
};


int main(int argc, char** argv){
	Solution s;
	//pfcout << s.numDistinct("daacaedaceacabbaabdccdaaeaebacddadcaeaacadbceaecddecdeedcebcdacdaebccdeebcbdeaccabcecbeeaadbccbaeccbbdaeadecabbbedceaddcde", "ceadbaa");
	pfcout << s.numDistinct("daacaedaceacabbaabdccdaaeaebacddadcaeaacadbceaecddecdeedcebcdacdaebccdeebcbdeaccabcecbeeaadbccbaeccbbdaeadecabbbedceaddcde", "ceadbaa");
	return 0;
}

