#include "common.h"

class Solution {
public:
    int numTrees(int n) {
        vector<int> vSaves(n + 1, 0);
        return numTreesImpl(n, vSaves);
    }

    int numTreesImpl(int n, vector<int>& vSaves) {
        if(n <= 0)
            return 1;

        if (vSaves[n] > 0)
            return vSaves[n];

        int cnt = 0;
        for(int i = 0; i < n; i++)
            cnt += numTreesImpl(i, vSaves) * numTreesImpl(n - i - 1, vSaves);
        
        vSaves[n] = cnt;
        return cnt;
    }

	vector<TreeNode *> generateTrees(int n) {
		return generateTreesImpl(1, n);
    }

	vector<TreeNode *> generateTreesImpl(int min, int max) {
		if(max < min)
			return vector<TreeNode *>(1, NULL);

		vector<TreeNode *> vTree;
        for(int i = min; i <= max; i++){
			vector<TreeNode *> vLeft(1, NULL);
			vector<TreeNode *> vRight(1, NULL);
			if(i != min){
				vLeft = generateTreesImpl(min, i - 1);
			}
			if(i != max)
				vRight = generateTreesImpl(i + 1, max);

			for(int m = 0; m < vLeft.size(); ++m){
				for(int n = 0; n < vRight.size(); ++n){
					TreeNode* pRoot = new TreeNode(i);
					pRoot->left = vLeft[m];
					pRoot->right = vRight[n];
					vTree.push_back(pRoot);
				}
			}
		}

		return vTree;
	}

};

void for_each_dump (TreeNode* pNode){
	pNode->dump();
}

class Functor{
public:
	void operator () (TreeNode* pNode){
		pNode->dump();
	}
};

int main(int argc, char** argv){
	int n = 3;
	if(argc > 1)
		n = atoi(argv[1]);
	Solution s;
	cout << s.numTrees(n) << endl;
	vector<TreeNode *> v(s.generateTrees(n));
	cout << v.size() << endl;
	Functor func;

	std::for_each(v.begin(), v.end(), func);
	return 0;
}
