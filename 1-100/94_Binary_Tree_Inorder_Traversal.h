#include "../definitions.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> path;
        recurse(root, path);
        return path;
    }

private:
    void recurse(TreeNode* root, vector<int>& path){
        if(!root) return;
        recurse(root->left, path);
        path.push_back(root->val);
        recurse(root->right, path);
    }
};