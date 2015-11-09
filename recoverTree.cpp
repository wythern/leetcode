#include "common.h"

class Solution {
public:
    // quick-sort select similar algorithm.
    // use the first element as the seperator, and find the right pos to swap.
    void recoverTree(TreeNode* root) {
        pair<TreeNode*, TreeNode*> wrongElements(NULL, NULL);
        bool bFound = false;
        traversalTree(root, wrongElements, bFound);
        cout << "first val = " << wrongElements.first->val << endl;
        cout << "second val = " << wrongElements.second->val << endl;
        swap(wrongElements.first->val, wrongElements.second->val);
    }
    
    void traversalTree(TreeNode* root, pair<TreeNode*, TreeNode*>& elements, bool& bFound){
        static TreeNode* prev = NULL;
        if(root->left) traversalTree(root->left, elements, bFound);
        if(bFound)
            return;

        if(prev && (prev->val > root->val)){
            if(!elements.first) {
                elements.first = prev;
            }
        }

        elements.second = root;
        if(elements.first && elements.first->val < root->val){
            cout << "candidate 2nd val = " << prev->val << endl;
            elements.second = prev;
            bFound = true;
            return;
        }
        prev = root;
        
        if(root->right) traversalTree(root->right, elements, bFound);
    }
};

int main(int argc, char** argv){

	//int array[] = {68,41,'#',-85,'#',-73,-49,-98,'#','#','#',-124};
    int array[] = {2, '#', 1};

    TreeNode tree(array, sizeof(array)/sizeof(int));
    tree.dump();

	Solution s;
    s.recoverTree(&tree);
    tree.dump();
	return 0;
}
