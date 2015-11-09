#include "common.h"

class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> buildingHeight;

		for (size_t i = 0; i < buildings.size(); i++)
		{
			vector<int>& building(buildings[i]);
			if (building[2] == 0)
				continue;
			buildingHeight.push_back(pair<int, int>(building[0], building[2]));
			buildingHeight.push_back(pair<int, int>(building[1], -building[2]));
		}
		
		std::sort(buildingHeight.begin(), buildingHeight.end());
		//map<int, vector<int>> buildingMap;
		vector<pair<int, int>> vSkyline;
		vector<int> visited;
		int lastH = -1;
		for (vector<pair<int, int>>::iterator it = buildingHeight.begin();
			it != buildingHeight.end(); ++it){
			if (it->second > 0){
				visited.insert(std::upper_bound(visited.begin(), visited.end(), it->second), it->second);
				//buildingMap[it->first] = visited;
			} else{
				int h = -it->second;
				visited.erase(find(visited.begin(), visited.end(), h));
			}
			//buildingMap[it->first] = visited;
			int h = 0;
			if (!visited.empty()){
				h = visited.back();
			}

			if(it->first == (it + 1)->first){
				continue;
			}

			if (h != lastH)
				vSkyline.push_back(pair<int, int>(it->first, h));
			lastH = h;
		}

		return vSkyline;
	}
};

int main(int argc, char** argv){
	Solution s;
	int A[] = {  2,  9, 10,
				 3,  7, 15,
				 5, 12, 12,
				15, 20, 10,
				19, 24,  8 };
	
	vector<vector<int>> buildings(Init2DTable<int>(A, 5, 3));
	vector<pair<int, int>> skyline = s.getSkyline(buildings);

	for (int i = 0; i < skyline.size(); ++i) {
		cout << "[" << skyline[i].first << ", " << skyline[i].second << "]" << endl;
	}
	return 0;
}

