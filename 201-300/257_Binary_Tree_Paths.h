#include <vector>
#include <string>
#include "../definitions.h"
using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        string path;
        vector<string> res;
        recurse(root, path, res);
        return res;
    }

private:
    void recurse(TreeNode* root, string& path, vector<string>& res){
        path += to_string(root->val);

        if(!root->left && !root->right){
            res.push_back(path);
        }
        else{
            path += "->";
            if(root->left){
                recurse(root->left, path, res);
            }

            if(root->right){
                recurse(root->right, path, res);
            }

            path.pop_back();
            path.pop_back();
        }

        while(!path.empty() && path.back() != '>')
            path.pop_back();
    }
};