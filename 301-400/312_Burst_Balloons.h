#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        nums.resize(n + 2);
        for(int i = n; i > 0; i--){
            nums[i] = nums[i - 1];
        }
        nums[0] = 1, nums[n + 1] = 1;

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for(int len = 1; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                int j = i + len + 1;
                for(int k = i + 1; k < j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]);
            }
        }

        return dp[0][n + 1];
    }
};


//缓存命中优化
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        nums.resize(n + 2);
        for(int i = n; i > 0; i--){
            nums[i] = nums[i - 1];
        }
        nums[0] = 1, nums[n + 1] = 1;

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 2; j <= n + 1; j++){
                for(int k = i + 1; k < j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]);
            }
        }

        return dp[0][n + 1];
    }
};


//vector 与 数组有性能上的差别
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        nums.resize(n + 2);
        for(int i = n; i > 0; i--){
            nums[i] = nums[i - 1];
        }
        nums[0] = 1, nums[n + 1] = 1;

        int dp[n + 2][n + 2];
        for(int i = 0; i <= n; i++)
            for(int j = i + 1; j <= n + 1; j++)
                dp[i][j] = 0;

        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 2; j <= n + 1; j++){
                for(int k = i + 1; k < j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]);
            }
        }

        return dp[0][n + 1];
    }
};