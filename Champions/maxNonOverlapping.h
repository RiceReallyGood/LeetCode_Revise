#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> count;
        count.insert({0,0});
        vector<int> dp(n + 1, 0);

        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            dp[i + 1] = dp[i];
            sum += nums[i];
            int prev = sum - target;
            if(count.find(prev) != count.end()){
                dp[i + 1] = max(dp[i + 1], dp[count[prev]] + 1);
            }
            count[sum] = i + 1;
        }

        return dp[n];
    }
};