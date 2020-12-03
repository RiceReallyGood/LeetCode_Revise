#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        vector<int> dp(2 * sum + 1, 0);
        dp[sum] = 1;

        for(int i = 0; i < nums.size(); i++){
            int v = nums[i];
            vector<int> temp(2 * sum + 1, 0);
            for(int j = v; j <= 2 * sum; j++){
                temp[j] += dp[j - v];
            }

            for(int j = 0; j <= 2 * sum - v; j++){
                temp[j] += dp[j + v];
            }

            dp.swap(temp);
        }

        return (S > sum || S < -sum) ? 0 : dp[S + sum];
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if(S + sum < 0 || (S + sum) % 2 == 1)
            return 0;
        
        S = (S + sum) / 2;
        vector<int> dp(S + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            int v = nums[i];
            for(int j = S; j >= v; j--)
                dp[j] += dp[j - v];
        }
        return dp[S];
    }
};