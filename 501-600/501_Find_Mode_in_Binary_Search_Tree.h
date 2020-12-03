#include <climits>
#include <vector>

#include "../definitions.h"
using namespace std;

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int prevnum = INT_MIN, prevcount = 0, maxcount = 0;

        recurse(root, prevnum, prevcount, res, maxcount);

        return res;
    }

private:
    void recurse(TreeNode* node, int& prevnum, int& prevcount, vector<int>& res, int& maxcount) {
        if (!node) return;

        recurse(node->left, prevnum, prevcount, res, maxcount);

        prevcount = node->val == prevnum ? prevcount + 1 : 1;
        prevnum = node->val;
        if (prevcount > maxcount) {
            res.clear();
            res.push_back(node->val);
            maxcount = prevcount;
        } else if (prevcount == maxcount) {
            res.push_back(node->val);
        }

        recurse(node->right, prevnum, prevcount, res, maxcount);
    }
};