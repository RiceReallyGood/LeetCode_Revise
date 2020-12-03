#include <vector>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));

        vector<int> psum(n + 1, 0);
        for(int i = 0; i < n; i++){
            psum[i + 1] = psum[i] + nums[i];
        }

        for(int i = n - 1; i >= 0; i--){
            dp[i][i] = nums[i];

            for(int j = i + 1; j < n; j++){
                dp[i][j] = psum[j + 1] - psum[i] - min(dp[i][j - 1], dp[i + 1][j]);
            }
        }

        return dp[0][n - 1] >= psum[n] - dp[0][n - 1];
    }
};

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for(int i = n - 1; i >= 0; i--){
            dp[i][i] = nums[i];

            for(int j = i + 1; j < n; j++){
                dp[i][j] =  max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }

        return dp[0][n - 1] >= 0;
    }
};