#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() < 2) return nums;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxlen = 0, endindex = -1;
        vector<int> dp(n, 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            if(dp[i] > maxlen){
                maxlen = dp[i];
                endindex = i;
            }
        }

        vector<int> ret = { nums[endindex] };
        for(int i = endindex - 1; i >= 0; i--){
            if(ret.back() % nums[i] == 0 && dp[i] == maxlen - ret.size())
                ret.push_back(nums[i]);
        }
        return ret;
    }
};