#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= m; i++){
            dp[i][0] = 1;
            for(int j = 1; j <= n; j++){
                dp[i][j] = dp[i - 1][j];
                if(s[i - 1] == t[j - 1])
                    dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<long> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= m; i++){
            for(int j = n; j > 0; j--){
                if(s[i - 1] == t[j - 1])
                    dp[j] += dp[j - 1];
            }
        }
        return dp[n];
    }
};