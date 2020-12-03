#include <vector>
#include <unordered_map>
#include "../definitions.h"
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> index;
        for(int i = 0; i < inorder.size(); i++)
            index[inorder[i]] = i;
        return recurse(postorder, int(postorder.size()) - 1, index, 0, int(inorder.size()) - 1);
    }

private:
    TreeNode* recurse(vector<int>& postorder, int end, unordered_map<int, int>& index, int l, int r){
        if(l > r) return nullptr;
        TreeNode* root = new TreeNode(postorder[end]);
        int c = index[postorder[end]];
        root->right = recurse(postorder, end - 1, index, c + 1, r);
        root->left = recurse(postorder, end - (r - c) - 1, index, l, c - 1);
        return root;
    }
};