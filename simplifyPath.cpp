#include "common.h"

class Solution {
public:
    string simplifyPath(string path) {
		int start = 0;
		int end = 0;
		vector<string> stackPath;
		string strMedium;
		// head
		start = path.find('/', 0);
		if(start != 0){
			strMedium = string(path.begin(), path.begin() + start);
			if(strMedium == string("..")){
				if(!stackPath.empty())
					stackPath.pop_back();
			}else{
				if(!strMedium.empty() && strMedium != string("."))
					stackPath.push_back(strMedium);
			}
		}
		++start;

		// body
        while((end = path.find('/', start)) != path.npos){
			strMedium = string(path.begin() + start, path.begin() + end);
			if(strMedium == string("..")){
				if(!stackPath.empty())
					stackPath.pop_back();
			}else{
				if(!strMedium.empty() && strMedium != string("."))
					stackPath.push_back(strMedium);
			}
			
			start = end+1;
		}

		// tail
		if(start < path.size()){
			strMedium = string(path.begin() + start, path.end());
			if(strMedium == string("..")){
				if(!stackPath.empty())
					stackPath.pop_back();
			}else{
				if(!strMedium.empty() && strMedium != string("."))
					stackPath.push_back(strMedium);
			}
		}

		string strSimpPath(1, '/');
		for(int i = 0; i < stackPath.size(); ++i){
			strSimpPath += stackPath[i] + string(1, '/');
		}

		if(strSimpPath.size() > 1)
			strSimpPath.erase(strSimpPath.size() - 1);

		return strSimpPath;
    }
};

int main(int argc, char** argv){
	if(argc < 2){
		exit(0);
	}

	string strPath(argv[1]);
	Solution s;
	cout << s.simplifyPath(strPath);
	return 0;
}
