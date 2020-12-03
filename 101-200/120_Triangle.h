#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        int n = triangle.size();
        vector<int> dp(n, 0);
        dp[0] = triangle[0][0];
        for(int i = 1; i < n; i++){
            dp[i] = dp[i - 1] + triangle[i][i];
            for(int j = i - 1; j > 0; j--)
                dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
            dp[0] += triangle[i][0];
        }
        int ret = dp[0];
        for(int i = 0; i < n; i++)
            ret = min(ret, dp[i]);
        return ret;
    }
};