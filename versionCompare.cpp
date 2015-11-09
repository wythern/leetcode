#include "common.h"

class Solution {
public:
	int compareVersion(string version1, string version2) {
		vector<int> v1 = spiltVersion(version1);
		vector<int> v2 = spiltVersion(version2);
		int i = 0;
		int j = 0;
		while (i < v1.size() && j < v2.size() && v1[i] == v2[j]){
			++i;
			++j;
		}

		if (i == v1.size() && j == v2.size())
			return 0;
		else if (i == v1.size() && j < v2.size()){
			bool bEqual = true;
			while (j < v2.size()){
				if (v2[j] != 0){
					bEqual = false;
					break;
				}
				++j;
			}

			return bEqual ? 0 : -1;
		}
		else if (i < v1.size() && j == v2.size()){
			bool bEqual = true;
			while (i < v1.size()){
				if (v1[i] != 0){
					bEqual = false;
					break;
				}
				++i;
			}
			return bEqual ? 0 : 1;
		}
		else
			return v1[i] < v2[j] ? -1 : 1;
	}

	vector<int> spiltVersion(string version){
		vector<int> vVersions;
		int posB = 0;
		int posE = version.find_first_of('.');
		while (posE != string::npos)
		{
			string strV(version.c_str() + posB, version.c_str() + posE);
			vVersions.push_back(atoi(strV.c_str()));
			posB = posE + 1;
			posE = version.find('.', posB);
		}

		string strV(version.c_str() + posB, version.c_str() + version.size());
		vVersions.push_back(atoi(strV.c_str()));
		return vVersions;
	}
};

int main(int argc, char** argv){
	Solution s;
	string v1("01.12.003.4.6");
	string v2("1.12.03.4.06.0.0.0.0.0.1");
	cout << s.compareVersion(v1, v2) << endl;
	return 0;
}
