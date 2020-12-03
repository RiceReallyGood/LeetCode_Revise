#include "../definitions.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n < 1) return {};
        return recurse(1, n);
    }

private:
    vector<TreeNode*> recurse(int l, int r){
        if(l > r) return {nullptr};
        vector<TreeNode*> ret;
        for(int c = l; c <= r; c++){
            vector<TreeNode*> lts = recurse(l, c - 1);
            vector<TreeNode*> rts = recurse(c + 1, r);
            for(int i = 0; i < lts.size(); i++){
                for(int j = 0; j < rts.size(); j++){
                    TreeNode* root = new TreeNode(c);
                    root->left = lts[i];
                    root->right = rts[j];
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
};