#include <vector>
#include "../definitions.h"
using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return ToBalancedTree(nums, 0, int(nums.size()) - 1);
    }

private:
    TreeNode* ToBalancedTree(vector<int>& nums, int l, int r){
        if(l > r) return nullptr;
        int c = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[c]);
        root->left = ToBalancedTree(nums, l, c - 1);
        root->right = ToBalancedTree(nums, c + 1, r);
        return root;
    }
};