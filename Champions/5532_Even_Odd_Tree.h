#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int evensz = q.size();
            int prev = 0;
            for(int i = 0; i < evensz; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->val % 2 != 1 || node->val <= prev)
                    return false;
                
                prev = node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            int oddsz = q.size();
            prev = 1e7 + 1;
            for(int i = 0; i < oddsz; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->val % 2 != 0 || node->val >= prev)
                    return false;
                
                prev = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return true;
    }
};