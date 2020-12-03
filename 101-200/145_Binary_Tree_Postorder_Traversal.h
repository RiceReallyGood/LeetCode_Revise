#include "../definitions.h"
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

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

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> s;
        stack<bool> rightvisited;
        TreeNode* p = root;
        bool secondtime = false;
        while(!s.empty() || p){
            if(p == nullptr){
                p = s.top();
                secondtime = rightvisited.top();
                s.pop();
                rightvisited.pop();
                if(secondtime){
                    ret.push_back(p->val);
                    p = nullptr;
                }
                else{
                    s.push(p);
                    rightvisited.push(true);
                    p = p->right;
                }
            }
            else{
                s.push(p);
                rightvisited.push(false);
                p = p->left;
            }
        }
        return ret;
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

    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ret;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* p = s.top();
            s.pop();
            ret.push_back(p->val);
            if(p->left) s.push(p->left);
            if(p->right) s.push(p->right);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};