#include <vector>
using namespace std;

class Solution { //may overflow
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for(int j = 1; j < n; j++)
            dp[0][j] = obstacleGrid[0][j] == 1 ? 0 : dp[0][j - 1];
        
        for(int i = 1; i < m; i++){
            dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i - 1][0];
            for(int j = 1; j < n; j++){
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : (dp[i - 1][j] + dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector<vector<bool>> reachable(m, vector<bool>(n, false));
        reachable[m - 1][n - 1] = true;
        for(int j = n - 2; j >= 0; j--)
            reachable[m - 1][j] = obstacleGrid[m - 1][j] == 1 ? false : reachable[m - 1][j + 1];
        
        for(int i = m - 2; i >= 0; i--){
            reachable[i][n - 1] = obstacleGrid[i][n - 1] == 1 ? false : reachable[i + 1][n - 1];
            for(int j = n - 2; j >= 0; j--){
                reachable[i][j] = obstacleGrid[i][j] == 1 ? false : (reachable[i][j + 1] || reachable[i + 1][j]);
            }
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for(int j = 1; j < n; j++){
            if(!reachable[0][j]) break;
            dp[0][j] = 1;
        }

        for(int i = 1; i < m; i++){
            dp[i][0] = reachable[i][0] ? dp[i - 1][0] : 0;
            for(int j = 1; j < n; j++)
                dp[i][j] = reachable[i][j] ? (dp[i - 1][j] + dp[i][j - 1]) : 0;
        }
        return dp[m - 1][n - 1];
    }
};