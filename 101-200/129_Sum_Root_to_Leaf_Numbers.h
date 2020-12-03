#include "../definitions.h"

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;
        int num = 0, sum = 0;
        recurse(root, num, sum);
        return sum;
    }

private:
    void recurse(TreeNode* root, int& num, int& sum){
        num = num * 10 + root->val;
        if(!root->left && !root->right)
            sum += num;
        
        if(root->left) recurse(root->left, num, sum);
        if(root->right) recurse(root->right, num, sum);
        num /= 10;
    }
};