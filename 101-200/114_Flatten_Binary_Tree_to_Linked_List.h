#include "../definitions.h"

class Solution {
public:
    void flatten(TreeNode* root) {
        recurse(root, root);
    }

private:
    void recurse(TreeNode* root, TreeNode* &node){
        if(root == nullptr) return;

        node = root;
        if(root->left){
            node = root->left;
            recurse(node, node);
            node->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        if(node->right){
            node = node->right;
            recurse(node, node);
        }
    }
};

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* last = nullptr;
        return recurse(root, last);
    }

private:
    void recurse(TreeNode* root, TreeNode* &last){
        if(root == nullptr) return;

        recurse(root->right, last);
        recurse(root->left, last);
        root->left = nullptr;
        root->right = last;
        last = root;
    }
};