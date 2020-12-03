#include "../definitions.h"
#include <string>
#include <queue>
using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string ret;
        while(!q.empty()){
            int levelsz = q.size();
            for(int i = 0; i < levelsz; i++){
                TreeNode* p = q.front();
                q.pop();
                if(!p){
                    ret += "null,";
                }
                else{
                    ret += to_string(p->val) + ',';
                    q.push(p->left);
                    q.push(p->right);
                }
            }
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "null,") return nullptr;
        int idx = 0;
        while(data[idx] != ',') idx++;
        TreeNode * root = new TreeNode(stoi(data.substr(0, idx)));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int levelsz = q.size();
            for(int i = 0; i < levelsz; i++){
                TreeNode* p = q.front();
                q.pop();
                if(!p) continue;
                int comma_idx = ++idx;
                while(data[comma_idx] != ',') comma_idx++;
                if(data.substr(idx, comma_idx - idx) != "null"){
                    p->left = new TreeNode(stoi(data.substr(idx, comma_idx - idx)));
                    q.push(p->left);
                }
                idx = comma_idx + 1;
                comma_idx = idx;
                while(data[comma_idx] != ',') comma_idx++;
                if(data.substr(idx, comma_idx - idx) != "null"){
                    p->right = new TreeNode(stoi(data.substr(idx, comma_idx - idx)));
                    q.push(p->right);
                }
                idx = comma_idx;
            }
        }
        return root;
    }
};