#include "../definitions.h"
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recurse(preorder, 0, inorder, 0, int(inorder.size()) - 1);
    }

private:
    TreeNode* recurse(vector<int>& preorder, int beg, vector<int>& inorder, int l, int r){
        if(l > r) return nullptr;
        TreeNode* root = new TreeNode(preorder[beg]);
        if(l == r) return root;
        int c = l;
        while(inorder[c] != preorder[beg]) c++;
        root->left = recurse(preorder, beg + 1, inorder, l, c - 1);
        root->right = recurse(preorder, beg + c - l + 1, inorder, c + 1, r);
        return root;
    }
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> index;
        for(int i = 0; i < inorder.size(); i++)
            index[inorder[i]] = i;
        return recurse(preorder, 0, index, 0, int(inorder.size()) - 1);
    }

private:
    TreeNode* recurse(vector<int>& preorder, int beg, unordered_map<int,int>& index, int l, int r){
        if(l > r) return nullptr;
        TreeNode* root = new TreeNode(preorder[beg]);
        int c = index[preorder[beg]];
        root->left = recurse(preorder, beg + 1, index, l, c - 1);
        root->right = recurse(preorder, beg + c - l + 1, index, c + 1, r);
        return root;
    }
};