#include <vector>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                dp[i][j] = min(i + 1 + dp[i + 1][j], j + 1 + dp[i][j - 1]);
                for(int k = i + 1; k < j; k++)
                    dp[i][j] = min(dp[i][j], max(dp[i][k - 1], dp[k + 1][j]) + k + 1);
            }
        }

        return dp[0][n - 1];
    }
};

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                int temp = min(i + 1 + dp[i + 1][j], j + 1 + dp[i][j - 1]);
                for(int k = i + 1; k < j; k++)
                    temp = min(temp, max(dp[i][k - 1], dp[k + 1][j]) + k + 1);
                
                dp[i][j] = temp;
            }
        }

        return dp[0][n - 1];
    }
};