#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        
        for(int i = n - 2; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp[0][n - 1];
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<int> dp(n, 0);

        dp[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--){
            int temp = 0;
            dp[i] = 1;
            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j]){
                    swap(temp, dp[j]);
                    dp[j] += 2;
                }
                else{
                    temp = dp[j];
                    dp[j] = max(dp[j], dp[j - 1]);
                }
            }
        }

        return dp[n - 1];
    }
};