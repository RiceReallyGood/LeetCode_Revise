#include "../definitions.h"
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        recurse(root, res);
        return res;
    }

private:
    void recurse(TreeNode* root, vector<int>& vals){
        if(root == nullptr) return;
        vals.push_back(root->val);
        recurse(root->left, vals);
        recurse(root->right, vals);
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ret;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* p = s.top();
            s.pop();
            ret.push_back(p->val);
            if(p->right) s.push(p->right);
            if(p->left) s.push(p->left);
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(!s.empty() || p){
            if(p == nullptr){
                p = s.top();
                s.pop();
                p = p->right;
            }
            else{
                ret.push_back(p->val);
                s.push(p);
                p = p->left;
            }
        }
        return ret;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(!s.empty() || p){
            if(p == nullptr){
                p = s.top();
                s.pop();
                ret.push_back(p->val);
                p = p->right;
            }
            else{
                s.push(p);
                p = p->left;
            }
        }
        return ret;
    }
};