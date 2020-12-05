#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty()) return 0;
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = s[i] == s[j] ? dp[i][j - 1] : 1 + dp[i + 1][j];
                for (int k = i + 1; k < j; k++)
                    if (s[i] == s[k])
                        dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j]);
            }
        }

        return dp[0][n - 1];
    }
};