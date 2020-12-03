#include "../definitions.h"
#include <algorithm>
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) swap(p, q);
        while(true){
            if(root->val < p->val)
                root = root->right;
            else if(root->val <= q->val)
                return root;
            else
                root = root->left;
        }
        return root;
    }
};