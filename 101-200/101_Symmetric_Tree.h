#include "../definitions.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return isSymmetric(root->left, root->right);
    }

private:
    bool isSymmetric(TreeNode* t1, TreeNode* t2){
        if(t1 == nullptr || t2 == nullptr) return t1 == t2;
        if(t1->val != t2->val) return false;
        return isSymmetric(t1->left, t2->right) && isSymmetric(t1->right, t2->left);
    }
};