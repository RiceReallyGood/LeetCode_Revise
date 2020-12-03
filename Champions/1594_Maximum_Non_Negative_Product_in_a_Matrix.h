#include <vector>
using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        using ll = long long;
        int n = grid.size(), m = grid[0].size();
        vector<vector<ll>> dp1(n, vector<ll>(m)), dp2(n, vector<ll>(m));

        dp1[0][0] = dp2[0][0] = grid[0][0];
        
        for(int j = 1; j < m; j++){
            dp1[0][j] = dp2[0][j] = dp2[0][j - 1] * grid[0][j];
        }

        for(int i = 1; i < n; i++){
            dp1[i][0] = dp2[i][0] = dp2[i - 1][0] * grid[i][0];

            for(int j = 1; j < m; j++){
                if(grid[i][j] >= 0){
                    dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) * grid[i][j];
                    dp2[i][j] = min(dp2[i - 1][j], dp2[i][j - 1]) * grid[i][j];
                }
                else{
                    dp1[i][j] = min(dp2[i - 1][j], dp2[i][j - 1]) * grid[i][j];
                    dp2[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) * grid[i][j];
                }
            }
        }

        if(dp1[n - 1][m - 1] < 0) return -1;
        return dp1[n - 1][m - 1] % ll(1e9 + 7);
    }
};