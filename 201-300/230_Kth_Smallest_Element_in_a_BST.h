#include "../definitions.h"

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        int count = 0, res = -1;
        recurse(root, count, res);
        return res;
    }

private:
    int k;
    void recurse(TreeNode* root, int& count,int& res){
        if(root == nullptr) return;
        recurse(root->left, count, res);
        if(++count == k) res = root->val;

        if(count < k)
            recurse(root->right, count, res);
    }
};