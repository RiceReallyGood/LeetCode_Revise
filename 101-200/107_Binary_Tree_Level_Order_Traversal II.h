#include <vector>
#include "../definitions.h"
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ret;

        while(!q.empty()){
            vector<int> thislevel;
            int levelsz = q.size();
            for(int i = 0; i < levelsz; i++){
                TreeNode* p = q.front();
                q.pop();
                thislevel.push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            ret.push_back(thislevel);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};