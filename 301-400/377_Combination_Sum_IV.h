#include <vector>
using namespace std;

class Solution { //overflow
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for(int sum = 1; sum <= target; sum++){
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] > sum) continue;
                dp[sum] += dp[sum - nums[i]];
            }
        }

        return dp[target];
    }
};

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target + 1, -1);
        memo[0] = 1;

        return helper(nums, memo, target);
    }

private:
    int helper(vector<int>& nums, vector<int>& memo, int target){
        if(memo[target] != -1) return memo[target];

        memo[target] = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= target)
                memo[target] += helper(nums, memo, target - nums[i]);
        }
        return memo[target];
    }
};