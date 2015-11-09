#include "common.h"

class Solution {
public:
	int totalNQueens(int n) {
		vector<vector<int> >  vInts = solveNQueensImpl(n);
		return vInts.size();
    }

    vector<vector<string> > solveNQueens(int n) {
		vector<vector<int> >  vInts = solveNQueensImpl(n);
		vector<vector<string> >  vSolution;
		for(int i = 0; i < vInts.size(); ++i){
			vector<string> vStr;
			string s(n, '.');
			for(int j = 0; j < vInts[i].size(); ++j){
				s[vInts[i][j]] = 'Q';
				vStr.push_back(s);
				s[vInts[i][j]] = '.';
			}
			vSolution.push_back(vStr);
		}
		return vSolution;
    }

	vector<vector<int> > solveNQueensImpl(int n){
		//int *v = (int*)malloc(sizeof(int)*n); // visited;
		int v[n];
		memset(v, 0xFF, sizeof(int)*n);
		int c[n]; // coloum;
		memset(c, 0, sizeof(int)*n);
		int d[2*n - 1]; // dig;
		memset(d, 0, sizeof(int)*(2*n - 1));
		int rd[2*n - 1];// reverse-dig;
		memset(rd, 0, sizeof(int)*(2*n - 1));

		vector<vector<int> > vS;
		vector<int> s;
		int y = 0;
		while(y < n){
			bool bGetCandidate = false;
			for(int x = 0; x < n; ++x){
				if(!c[x] && !d[x+y] && !rd[n-1+x-y] && x > v[y]){
					s.push_back(x);
					v[y] = x;
					c[x] = 1;
					d[x+y] = 1;
					rd[n-1+x-y] = 1;
					bGetCandidate = true;
					break;
				}
			}

			if(!bGetCandidate){
				if(s.empty()){
					break;
				}else{
					int x = s.back();
					s.pop_back();
					v[y] = -1;
					--y;
					c[x] = 0;
					d[x+y] = 0;
					rd[n-1+x-y] = 0;
				}
			}else{
				++y;
				if(y == n){
					vS.push_back(s);
					int x = s.back();
					s.pop_back();
					y = n - 1;
					c[x] = 0;
					d[x+y] = 0;
					rd[n-1+x-y] = 0;
				}
			}
		}

		return vS;
	}
};

int main(int argc, char** argv){
	Solution s;
	
	int n = 1;
	if(argc > 1){
		n = atoi(argv[1]);
	}

	int c = s.totalNQueens(n);
	cout << "Total " << c << " solutions." << endl;
	vector<vector<string> > vResults(s.solveNQueens(n));
	for(int i = 0; i < vResults.size(); ++i)
		printContainer<vector<string> >(vResults[i], vResults[i].size(), "Result\n", true);
	return 0;
}
