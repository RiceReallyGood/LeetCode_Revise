#include <algorithm>
#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int N = ring.length();
        vector<vector<int>> indices(26);
        for (int i = 0; i < N; i++)
            indices[ring[i] - 'a'].push_back(i);

        vector<int> dp(N, INT_MAX);
        for (int idx : indices[key[0] - 'a'])
            dp[idx] = min(idx, N - idx) + 1;

        for (int i = 1; i < key.length(); i++) {
            char c = key[i], prevc = key[i - 1];
            if (c == prevc) {
                for (int i = 0; i < N; i++) {
                    if (dp[i] != INT_MAX)
                        dp[i]++;
                }
                continue;
            }
            vector<int> temp(N, INT_MAX);

            for (int idx : indices[c - 'a']) {
                for (int previdx : indices[prevc - 'a']) {
                    int dist = idx > previdx ? min(idx - previdx, N + previdx - idx) : min(previdx - idx, N + idx - previdx);
                    temp[idx] = min(temp[idx], dp[previdx] + dist + 1);
                }
            }

            swap(dp, temp);
        }

        return *min_element(dp.begin(), dp.end());
    }
};