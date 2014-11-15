/*
 *For example, given array S = {-1 0 1 2 -1 -4},
 *  A solution set is:
 *  (-1,  0, 1)
 *  (-1, -1, 2)
*/

#include "common.h"

class Solution {
public:
	//brute-force
	vector<vector<int> > threeSum(vector<int> &num) {
		if(num.empty())
			return vector<vector<int> >();

		int n = num.size();
		set<vector<int> > vResult;
        for(int i = 0; i < n; ++i)
			for(int j = 0; j < i; ++j)
				for(int k = 0; k < j; ++k){
					int sum = num[i] + num[j] + num[k];
					if(!sum && (i != j && j != k && i != k)){
                        vector<int> vSolution;
                        vSolution.push_back(num[i]);
                        vSolution.push_back(num[j]);
                        vSolution.push_back(num[k]);
                        std::sort(vSolution.begin(), vSolution.end());
                        vResult.insert(vSolution);
					}
				}

		std::vector<std::vector<int> > v(vResult.begin(), vResult.end());
		return v;
	}

	//map based
    vector<vector<int> > threeSum1(vector<int> &num) {
		if(num.empty())
			return vector<vector<int> >();
		int n = num.size();
		set<vector<int> > vResult;

		std::map<int, std::set<std::pair<int, int> > > vVisited;
        for(int i = 0; i < n; ++i){
			for(int j = i + 1; j < n; ++j){
				vVisited[num[i]+num[j]].insert(std::pair<int, int>(i, j));
			}
		}

		for(int i = 0; i < n; ++i){
			if(vVisited.find(-num[i]) != vVisited.end()){
				std::set<std::pair<int, int> >::iterator it;
				for(it = vVisited[-num[i]].begin();
					it != vVisited[-num[i]].end();
					++it){
					if(i != (*it).first && i != (*it).second){
                        vector<int> vSolution;
                        vSolution.push_back(num[i]);
                        vSolution.push_back(num[(*it).first]);
						vSolution.push_back(num[(*it).second]);
                        std::sort(vSolution.begin(), vSolution.end());
                        vResult.insert(vSolution);
					}
				}
			}
		}
		std::vector<std::vector<int> > v(vResult.begin(), vResult.end());
		return v;
    }

	//hash_map based
	vector<vector<int> > threeSum2(vector<int> &num) {
		if(num.empty())
			return vector<vector<int> >();

		int n = num.size();
		set<vector<int> > vResult;

		hash_map<int, std::set<std::pair<int, int> > > vVisited;
        for(int i = 0; i < n; ++i){
			for(int j = i + 1; j < n; ++j){
				vVisited[num[i]+num[j]].insert(std::pair<int, int>(i, j));
			}
		}

		for(int i = 0; i < n; ++i){
			if(vVisited.find(-num[i]) != vVisited.end()){
				std::set<std::pair<int, int> >::iterator it;
				for(it = vVisited[-num[i]].begin();
					it != vVisited[-num[i]].end();
					++it){
					if(i != (*it).first && i != (*it).second){
                        vector<int> vSolution;
                        vSolution.push_back(num[i]);
                        vSolution.push_back(num[(*it).first]);
						vSolution.push_back(num[(*it).second]);
                        std::sort(vSolution.begin(), vSolution.end());
                        vResult.insert(vSolution);
					}
				}
			}
		}
		std::vector<std::vector<int> > v(vResult.begin(), vResult.end());
		return v;
    }

	vector<vector<int> > threeSum3(vector<int> &num) {
		if(num.empty())
			return vector<vector<int> >();

		int n = num.size();
		set<vector<int> > vResult;

		hash_map<int, int> hashNums;
		for(int i = 0; i < n; ++i) {
			if (hashNums.find(num[i]) == hashNums.end())
				hashNums[num[i]] = 1;
			else
				hashNums[num[i]]++;
		}

        for(int i = 0; i < n; ++i){
			hashNums[num[i]]--;
			hash_map<int, int> savedMap = hashNums;
			for(int j = i + 1; j < n; ++j){
				hashNums[num[j]] --;
				int candidate = -(num[i]+num[j]);
				if(hashNums.find(candidate) != hashNums.end() &&
				   hashNums[candidate]){
					vector<int> vSolution;
					vSolution.push_back(num[i]);
					vSolution.push_back(num[j]);
					vSolution.push_back(candidate);
					std::sort(vSolution.begin(), vSolution.end());
					vResult.insert(vSolution);
					hashNums[candidate]--;
				}
				//hashNums[num[j]] ++;
			}
			//hashNums[num[i]]++;
			hashNums = savedMap;
		}


		std::vector<std::vector<int> > v(vResult.begin(), vResult.end());
		return v;
	}

};


int main(int argc, char** argv)
{
    Solution s;
    int A[] = {-6,-8,-9,4,-14,6,-10,7,12,13,4,9,7,14,-12,7,0,14,-1,-3,2,2,-3,11,-6,-10,-13,-13,1,-9,2,2,-2,8,-9,0,-9,-12,14,10,8,3,4,0,-6,7,14,9,6,-2,13,-15,8,-5,3,-13,-8,5,-11,0,11,6,-13,-14,-9,-15,-7,-11,10,-7,14,4,3,3,11,13,-13,11,-1,0,-6,-10,0,9,0,10,11,0,0,-14,-15,-12,-1,10,12,-2,2,-10,2,-2,-10,2,-13,1,12,5,-1,-15,1,5,-8,3,10,8};//{-1, 0, 1, 2, -1, -4};
    vector<int> vInput(A, A + sizeof(A)/sizeof(int));

#if 0
    vector<vector<int> > v = s.threeSum(vInput);

    for(int i = 0; i < v.size(); ++i){
        vector<int>::iterator it = v[i].begin();
        while(it != v[i].end()){
            std::cout << *it++ << ",";
        }
        std::cout << std::endl;
    }
#endif
	vector<vector<vector<int> > > vTestResults;

	std::vector<int> vTest = generateRandomIntVector(1000, -10000, 10000);
	double ts = currentTimingMs();
	vTestResults.push_back(s.threeSum(vTest));
	std::cout << currentTimingMs() - ts << "ms" << std::endl;

	ts = currentTimingMs();
	vTestResults.push_back(s.threeSum1(vTest));
	std::cout << currentTimingMs() - ts << "ms" << std::endl;

	ts = currentTimingMs();
	vTestResults.push_back(s.threeSum2(vTest));
	std::cout << currentTimingMs() - ts << "ms" << std::endl;

	ts = currentTimingMs();
	vTestResults.push_back(s.threeSum3(vTest));
	std::cout << currentTimingMs() - ts << "ms" << std::endl;

	for(int i = 0; i < vTestResults.size() - 1; ++i)
		if ((!vTestResults[i].empty() || !vTestResults[i+1].empty()) &&
			vTestResults[i] != vTestResults[i+1]) {
			std::cout << "ERROR! "
					  << "v" << i
					  << "!="
					  << "v" << i+1
					  << std::endl;

			std::cout << "-------------------- Input[] --------------------" << std::endl;
			{
				vector<int>::iterator it = vTest.begin();
				while(it != vTest.end()){
					std::cout << *it++ << ",";
				}
				std::cout << std::endl;
			}

			std::cout << "-------------------- v" << i << "--------------------" << std::endl;
			for(int j = 0; j < vTestResults[i].size(); ++j){
				vector<int>::iterator it = vTestResults[i][j].begin();
				while(it != vTestResults[i][j].end()){
					std::cout << *it++ << ",";
				}
				std::cout << std::endl;
			}

			std::cout << "-------------------- but v" << i + 1 << "--------------------" << std::endl;
			for(int j = 0; j < vTestResults[i+1].size(); ++j){
				vector<int>::iterator it = vTestResults[i+1][j].begin();
				while(it != vTestResults[i+1][j].end()){
					std::cout << *it++ << ",";
				}
				std::cout << std::endl;
			}
			std::cout << "----------------- end -------------------" << std::endl;
			getchar();
		}

	std::cout << "Found " << vTestResults[0].size() << std::endl;
    return 0;
}
