#include "../definitions.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        preorder(root, 0, ret);
        return ret;

    }

private:
    void preorder(TreeNode* node, int depth, vector<int>& view){
        if(node == nullptr) return;
        if(depth == view.size())
            view.push_back(node->val);
        preorder(node->right, depth + 1, view);
        preorder(node->left, depth + 1, view);
    }
};