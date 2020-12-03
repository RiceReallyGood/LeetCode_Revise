#include "../definitions.h"
#include <queue>
using namespace std;

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(!node->left) return count;
            q.push(node->left);
            count++;

            if(!node->right) return count;
            q.push(node->right);
            count++;
        }
        return count;
    }
};