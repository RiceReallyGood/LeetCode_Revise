#include "../definitions.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return {};
        vector<vector<int>> ret;
        vector<int> path;
        recurse(root, path, sum, ret);
        return ret;
    }

private:
    void recurse(TreeNode* root, vector<int>& path, int& target, vector<vector<int>>& res){
        path.push_back(root->val);
        target -= root->val;
        if(!root->left && !root->right && target == 0){
            res.emplace_back(path);
        }

        if(root->left) recurse(root->left, path, target, res);
        if(root->right) recurse(root->right, path, target, res);
        target += root->val;
        path.pop_back();
    }
};