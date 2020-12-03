#include <algorithm>
#include <unordered_map>
#include <vector>

#include "../definitions.h"
using namespace std;

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (!root) return {};
        unordered_map<int, int> freq;
        int maxfreq = 0;
        count_freq(root, freq, maxfreq);

        vector<int> res;
        for(auto it = freq.begin(); it != freq.end(); it++){
            if(it->second == maxfreq)
                res.push_back(it->first);
        }
        return res;
    }

private:
    int count_freq(TreeNode* root, unordered_map<int, int>& freq, int& maxfreq) {
        if (!root) return 0;

        int sum = root->val + count_freq(root->left, freq, maxfreq) + count_freq(root->right, freq, maxfreq);

        maxfreq = max(maxfreq, ++freq[sum]);
        return sum;
    }
};