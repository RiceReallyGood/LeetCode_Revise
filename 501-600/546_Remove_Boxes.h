#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        if (boxes.empty()) return 0;
        vector<int> color, count;
        color.push_back(boxes[0]);
        count.push_back(1);

        for (int i = 1, idx = 0; i < boxes.size(); i++) {
            if (boxes[i] == color.back())
                count[idx]++;
            else {
                color.push_back(boxes[i]);
                count.push_back(1);
                idx++;
            }
        }

        int n = color.size();
        memset(memo, 0, sizeof memo);

        return helper(color, count, 0, n - 1, 0);
    }

private:
    int memo[100][100][100];
    int helper(vector<int>& color, vector<int>& count, int i, int j, int k) {
        if (memo[i][j][k] != 0) return memo[i][j][k];
        if (i == j) return memo[i][j][k] = (k + count[i]) * (k + count[i]);

        memo[i][j][k] = (k + count[j]) * (k + count[j]) + helper(color, count, i, j - 1, 0);

        for (int l = j - 1; l >= i; l--) {
            if (color[l] == color[j]) {
                memo[i][j][k] = max(memo[i][j][k], helper(color, count, i, l, k + count[j]) + helper(color, count, l + 1, j - 1, 0));
            }
        }

        return memo[i][j][k];
    }
};