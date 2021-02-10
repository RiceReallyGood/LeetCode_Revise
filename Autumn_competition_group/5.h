#include <algorithm>

#include "../definitions.h"
using namespace std;

class Solution {
public:
    int navigation(TreeNode* root) {
        bool extrainfo = false;
        int res = helper(root, extrainfo);
        return extrainfo ? res + 1 : res;
    }

private:
    int helper(TreeNode* root, bool& extrainfo) {
        int res = 0;
        bool lextra = false, rextra = false;

        if (root->left) res += helper(root->left, extrainfo);
        if (root->right) res += helper(root->right, extrainfo);

        if (lextra && rextra) res++;

        extrainfo = 0;
    }
};