#include "../definitions.h"
#include <algorithm>

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int ldepth = minDepth(root->left);
        int rdepth = minDepth(root->right);
        if(ldepth == 0 || rdepth == 0)
            return std::max(ldepth, rdepth) + 1;
        return std::min(ldepth, rdepth) + 1;
    }
};