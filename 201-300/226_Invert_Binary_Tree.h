#include "../definitions.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;

        TreeNode* invl = invertTree(root->left);
        TreeNode* invr = invertTree(root->right);
        root->left = invr;
        root->right = invl;
        return root;
    }
};