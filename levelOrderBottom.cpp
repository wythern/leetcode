class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > v;
        if(!root)
            return v;

        list<TreeNode*> upstack(1, root);
        list<TreeNode*> downstack;
        while(1){
            vector<int> vVals;
            while(!upstack.empty()){
                TreeNode* p = upstack.front();
                upstack.pop_front();
                vVals.push_back(p->val);
                if(p->left)
                    downstack.push_back(p->left);
                if(p->right)
                    downstack.push_back(p->right);
            }

            v.push_back(vVals);
            if(downstack.empty())
                break;
            swap(upstack, downstack);
        }
        std::reverse(v.begin(), v.end());
        return v;
    }
};