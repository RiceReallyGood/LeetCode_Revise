#include "../definitions.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        int pathsum = 0;
        return recurse(root, pathsum, sum);
    }

private:
    bool recurse(TreeNode* root, int& pathsum, int sum){
        pathsum += root->val;
        if(!root->left && !root->right){
            bool ret = (pathsum == sum);
            pathsum -= root->val;
            return ret;
        }

        if(root->left && recurse(root->left, pathsum, sum))
            return true;
        if(root->right && recurse(root->right, pathsum, sum))
            return true;
        
        pathsum -= root->val;
        return false;
    }
};