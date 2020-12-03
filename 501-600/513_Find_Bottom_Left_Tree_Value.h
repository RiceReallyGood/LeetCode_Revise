#include "../definitions.h"

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        res = 0, maxheight = -1;
        recurse(root, 0);
        return res;
    }

private:
    int res, maxheight;
    void recurse(TreeNode* node, int height) {
        if (!node) return;

        recurse(node->left, height + 1);
        recurse(node->right, height + 1);

        if (height > maxheight) {
            res = node->val;
            maxheight = height;
        }
    }
};