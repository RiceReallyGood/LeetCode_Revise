#include "../definitions.h"
#include <utility>


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        std::pair<int, int> interval;
        return recurse(root, interval);
    }

private:
    bool recurse(TreeNode* root, std::pair<int, int>& interval){
        if(!root) return true;
        std::pair<int,int> leftinterval, rightinterval;
        if(!recurse(root->left, leftinterval)) return false;
        if(!recurse(root->right, rightinterval)) return false;

        if(root->left){
            if(root->val <= leftinterval.second) return false;
            else interval.first = leftinterval.first;
        }
        else
            interval.first = root->val;
        
        if(root->right){
            if(root->val >= rightinterval.first) return false;
            else interval.second = rightinterval.second;
        }
        else
            interval.second = root->val;
        
        return true;
    }
};