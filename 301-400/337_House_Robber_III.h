#include "../definitions.h"
#include <utility>
#include <algorithm>

class Solution {
public:
    int rob(TreeNode* root) {
        std::pair<int, int> ret = helper(root);
        return std::max(ret.first, ret.second);
    }

private:
    std::pair<int, int> helper(TreeNode* root){
        if(!root) return std::make_pair(0, 0);

        std::pair<int, int> l = helper(root->left);
        std::pair<int, int> r = helper(root->right);
        return std::make_pair(root->val + l.second + r.second, 
                                std::max(l.first, l.second) + std::max(r.first, r.second));
    }
};