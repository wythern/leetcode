#include "common.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
		vector<int> line(n, 1);
		//printContainer<vector<int> >(line, line.size(), "line");
		for(int i = 1; i < m; ++i)
			for(int j = 1; j < n; ++j)
				line[j] += line[j-1];

		return line[n - 1];
    }

	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		if(*(obstacleGrid.begin()->begin()) == 1)
			return 0;
		else
			*(obstacleGrid.begin()->begin()) = 1;

		for(int i = 0; i < obstacleGrid.size(); ++i){
			for(int j = 0; j < obstacleGrid[i].size(); ++j){
				if((i == 0) && (j > 0)){
					obstacleGrid[i][j] = (obstacleGrid[i][j] == 0) ?
						obstacleGrid[i][j - 1]	: 0;
				}else if (i > 0){
					obstacleGrid[i][j] = (obstacleGrid[i][j] == 0) ?
						obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1]	: 0;
				}
			}
		}

		return obstacleGrid.back().back();
    }
};


int main(int argc, char** argv){
	if(argc < 3){
		exit(0);
	}

	Solution s;
	cout << "Total :" << s.uniquePaths(atoi(argv[1]), atoi(argv[2])) << endl;

	int array[][3] = {{0}};

	vector<vector<int> > grid;
	for(int i = 0; i < sizeof(array)/sizeof(array[0]); ++i){
		vector<int> v(array[i], array[i] + 3);
		grid.push_back(v);
	}
	cout << "Total with obstacle : " << s.uniquePathsWithObstacles(grid) << endl;
	return 0;
}
