#include "../definitions.h"
#include <cmath>
#include <algorithm>

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return recurse(root, height);
    }

private:
    bool recurse(TreeNode* root, int& height){
        if(root == nullptr){
            height = 0;
            return true;
        }

        int lheight = 0, rheight = 0;
        if(!recurse(root->left, lheight)) return false;
        if(!recurse(root->right, rheight)) return false;
        if(std::abs(lheight - rheight) > 1) return false;
        height = std::max(lheight, rheight) + 1;
        return true;
    }
};