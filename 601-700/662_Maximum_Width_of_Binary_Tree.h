#include <queue>
#include <vector>

#include "../definitions.h"
using namespace std;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {  //overflow
        if (!root) return 0;
        vector<int> l, r;
        leftbound(root, 0, 0, l);
        rightbound(root, 0, 0, r);

        int res = 0;
        for (int i = 0; i < l.size(); i++)
            res = max(res, r[i] - l[i] + 1);

        return res;
    }

private:
    void rightbound(TreeNode* root, int depth, int index, vector<int>& r) {
        if (depth == r.size()) r.push_back(index);
        if (root->right) rightbound(root->right, depth + 1, index * 2 + 1, r);
        if (root->left) rightbound(root->left, depth + 1, index * 2, r);
    }

    void leftbound(TreeNode* root, int depth, int index, vector<int>& l) {
        if (depth == l.size()) l.push_back(index);
        if (root->left) leftbound(root->left, depth + 1, index * 2, l);
        if (root->right) leftbound(root->right, depth + 1, index * 2 + 1, l);
    }
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<int> index;
        queue<TreeNode*> q;
        q.push(root);
        index.push(0);

        int res = 0;
        while (!q.empty()) {
            int sz = q.size();
            int l = index.front();
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                int idx = index.front();
                q.pop(), index.pop();

                if (node->left) {
                    q.push(node->left);
                    index.push(2 * (idx - l));
                }

                if (node->right) {
                    q.push(node->right);
                    index.push(2 * (idx - l) + 1);
                }

                res = max(res, idx - l + 1);
            }
        }
        return res;
    }
};