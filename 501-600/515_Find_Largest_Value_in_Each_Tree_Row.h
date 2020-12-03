#include <climits>
#include <queue>
#include <vector>

#include "../definitions.h"
using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size(), maxele = INT_MIN;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                maxele = max(maxele, node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            res.push_back(maxele);
        }
        return res;
    }
};