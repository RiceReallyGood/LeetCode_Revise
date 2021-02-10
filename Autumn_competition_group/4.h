#include <vector>
using namespace std;

class Solution {
public:
    int keyboard(int k, int n) {
        long mod = 1e9 + 7;
        vector<vector<long>> attach(n, vector<long>(k + 1));
        for (int i = 0; i < n; i++) {
            attach[i][0] = 1;
            for (int j = 1; j <= k; j++)
                attach[i][j] = attach[i][j - 1] * (i + j) / j;
        }

        vector<long> dp(n + 1);
        dp[0] = 1;

        for (int c = 0; c < 26; c++) {
            for (int len = min(c * k, n); len >= 0; len--) {
                for (int i = 1; i <= min(k, n - len); i++) {
                    dp[len + i] = (dp[len + i] + dp[len] * attach[len][i]) % mod;
                }
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    int keyboard(int k, int n) {
        long mod = 1e9 + 7;
        vector<vector<long>> attach(n, vector<long>(k + 1, 1));
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++)
                attach[i][j] = (attach[i - 1][j] + attach[i][j - 1]) % mod;
        }

        vector<long> dp(n + 1);
        dp[0] = 1;

        for (int c = 0; c < 26; c++) {
            for (int len = min(c * k, n); len >= 0; len--) {
                for (int i = 1; i <= min(k, n - len); i++) {
                    dp[len + i] = (dp[len + i] + dp[len] * attach[len][i]) % mod;
                }
            }
        }
        return dp[n];
    }
};