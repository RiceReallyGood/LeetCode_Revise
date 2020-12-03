#include <vector>
#include "../definitions.h"
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        deque<TreeNode*> dq;
        dq.push_back(root);
        vector<vector<int>> ret;
        while(!dq.empty()){
            vector<int> level;
            int levelsz = dq.size();
            for(int i = 0; i < levelsz; i++){
                TreeNode* p = dq.front();
                dq.pop_front();
                level.push_back(p->val);
                if(p->left) dq.push_back(p->left);
                if(p->right) dq.push_back(p->right);
            }
            ret.emplace_back(level);
            if(dq.empty()) break;
            level.clear();
            levelsz = dq.size();
            for(int i = 0; i < levelsz; i++){
                TreeNode* p = dq.back();
                dq.pop_back();
                level.push_back(p->val);
                if(p->right) dq.push_front(p->right);
                if(p->left) dq.push_front(p->left);
            }
            ret.emplace_back(level);
        }
        return ret;
    }
};