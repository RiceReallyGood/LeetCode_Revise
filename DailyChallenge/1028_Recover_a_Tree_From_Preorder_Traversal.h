#include "../definitions.h"
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        int index = 0, len = S.length();
        vector<int> val, depth;
        while(index < len){
            int count = 0;
            while(S[index] == '-'){
                count++;
                index++;
            }
            depth.push_back(count);
            int num = 0;
            while(index < len && S[index] != '-')
                num = num * 10 + S[index++] - '0';
            val.push_back(num);
        }
        index = 0;
        return BuildTree(depth, val, 0, index);
    }

private:
    TreeNode* BuildTree(vector<int>& depth, vector<int>& val, int currdepth,int& index){
        if(index == depth.size() || depth[index] < currdepth) return nullptr;
        TreeNode* root = new TreeNode(val[index++]);
        root->left = BuildTree(depth, val, currdepth + 1, index);
        root->right = BuildTree(depth, val, currdepth + 1, index);
        return root;
    }
};