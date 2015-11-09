#include "common.h"

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int N = gas.size();
		if (0 == N)
			return -1;

		int i = 0;
		int f = 0;
		int c = 0;
		int s = 0;
		while (i < N){
			f += gas[c] - cost[c];
			while (f < 0 && s < N)
			{
				f += cost[s] - gas[s];
				++s;
				--i;
			}

			++c;
			++i;
			if (c == N)
				c = 0;
			if (s == N)
				break;
		}

		return (i == N && f >= 0) ? s : -1;
	}
};

int main(int argc, char** argv){
	int g[] = { 2};
	int c[] = { 2};
	vector<int> gas(g, g + sizeof(g) / sizeof(int));
	vector<int> cost(c, c + sizeof(c) / sizeof(int));
	Solution s;
	int id = s.canCompleteCircuit(gas, cost);
	cout << ((id == -1) ? string("CANNOT! ") : string("Can ")) << id << endl;
	return 0;
}