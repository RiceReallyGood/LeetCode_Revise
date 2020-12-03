#include "../definitions.h"
#include <vector>
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        
        FindPath(root, p, path1);
        FindPath(root, q, path2);

        for(int i = 0; i < path1.size(); i++){
            if(i == path1.size() - 1 | i == path2.size() - 1 || path1[i + 1] != path2[i + 1])
                return path1[i];
        }
        return nullptr;
    }

private:
    bool FindPath(TreeNode* root, TreeNode* p, vector<TreeNode*> path){
        if(root == nullptr) return false;

        path.push_back(root);

        if(p == root) return true;

        if(FindPath(root->left, p, path)) return true;
        if(FindPath(root->right, p, path)) return true;

        path.pop_back();
        return false;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->res = nullptr;

        findpq(root, p, q);
        return res;
    }

private:
    TreeNode* res;
    pair<bool, bool> findpq(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr) return {false, false};
        pair<bool, bool> ret = findpq(root->left, p, q);

        if(res == nullptr){
            pair<bool, bool> rfind = findpq(root->right, p, q);
            ret.first = ret.first || rfind.first;
            ret.second = ret.second || rfind.second;
        }

        if(res == nullptr){
            if(root == p) ret.first = true;
            if(root == q) ret.second = true;

            if(ret.first && ret.second) res = root;
        }
        return ret;
    }
};