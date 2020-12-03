#include "../definitions.h"
#include <algorithm>

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int treemaxsum = 0, rootmaxsum = 0;
        recurse(root, treemaxsum, rootmaxsum);
        return treemaxsum;
    }

private:
    void recurse(TreeNode* root, int& treemaxsum, int& rootmaxsum){
        if(!root) return;
        int ltmaxsum = 0, lrmaxsum = 0;
        recurse(root->left, ltmaxsum, lrmaxsum);
        int rtmaxsum = 0, rrmaxsum = 0;
        recurse(root->right, rtmaxsum, rrmaxsum);
        rootmaxsum = std::max(std::max(lrmaxsum, rrmaxsum), 0) + root->val;
        treemaxsum = root->val + std::max(lrmaxsum, 0) + std::max(rrmaxsum, 0);
        if(root->left) treemaxsum = std::max(ltmaxsum, treemaxsum);
        if(root->right) treemaxsum = std::max(rtmaxsum, treemaxsum);
    }
};