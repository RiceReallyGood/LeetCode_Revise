#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;

        if(sum & 1) return false;

        int half = sum / 2;
        vector<bool> dp(half + 1, false);
        dp[0] = true;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > half) return false;
            if(dp[half - nums[i]]) return true;

            for(int j = half; j >= nums[i]; j--)
                dp[j] = dp[j] || dp[j - nums[i]];
        }

        return false;
    }
};