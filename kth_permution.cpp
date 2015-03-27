#include "common.h"

class Solution {
public:
	string getPermutation(int n, int k) {
		//init num
		string num;
		for(int i = 1; i <= n; ++i)
			num.push_back(i + '0');

		//init factorials
		int* factorials = (int*)(malloc((n+1)*sizeof(int)));
		factorials[0] = 1;
		factorials[1] = 1;
		for(int i = 2; i <= n; ++i)
			factorials[i] = i * factorials[i - 1];

		if(k > factorials[n])
			return string();

		int begin = 0;
		int kth = k - 1;
		for(int i = n - 1; i >= 1; --i, ++begin){
			int pos = kth/factorials[i];
			if(pos != 0){
				std::swap(*(num.begin() + begin), *(num.begin() + begin + pos));
				std::sort(num.begin() + begin + 1, num.end());
			}
			kth = kth % factorials[i];
		}

		return num;
    }
};

int main(int argc, char** argv){
    if(argc < 3){
        exit(0);
    }
	Solution s;
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    string strKthNum = s.getPermutation(n, k);
    cout << "Kth string = " << strKthNum << endl;
	return 0;
}	
