#include "common.h"

class Solution {
public:
	bool isAdditiveNumber(string num) {
		//backtracing.
		for (size_t i = 1; i < num.size(); i++)
		{
			string numback1 = num.substr(0, i);
			for (size_t j = i + 1; j < num.size(); j++)
			{
				string numback2 = num.substr(i, j - i);
				if (isAdditiveNumberImpl(num, j, numback1, numback2)){
					return true;
				}
			}
		}

		return false;
	}

	bool isAdditiveNumberImpl(string& num, int start, string& numback1, string& numback2){
		if (start >= num.size()){
			return true;
		}
		string strResult = stringNumberAdd(numback1, numback2);
		string strHeader = num.substr(start, strResult.size());

		if (strResult == strHeader){
			return isAdditiveNumberImpl(num, start + strResult.size(), numback2, strResult);
		}

		return false;
	}

	string stringNumberAdd(string& str1, string& str2){
		string strResult;
		int i = str1.size() - 1;
		int j = str2.size() - 1;
		stack<char> chStack;
		int ch = 0;
		while (i >= 0 && j >= 0)
		{
			int digits = str1{i] - '0' + str2{j] - '0' + ch;
			chStack.push(digits % 10);
			ch = digits / 10;
			--i;
			--j;
		}

		while (i >= 0)
		{
			int digits = str1{i] - '0' + ch;
			chStack.push(digits % 10);
			ch = digits / 10;
			--i;
		}

		while (j >= 0)
		{
			int digits = str2{j] - '0' + ch;
			chStack.push(digits % 10);
			ch = digits / 10;
			--j;
		}

		if (ch)
			chStack.push(ch);

		while (!chStack.empty())
		{
			strResult.push_back(chStack.top() + '0');
			chStack.pop();
		}
		return strResult;
	}
};


int main(int argc, char** argv){
	Solution s;
	string strA("199100199");
	cout << s.isAdditiveNumber(strA) << endl;
	return 0;
}
