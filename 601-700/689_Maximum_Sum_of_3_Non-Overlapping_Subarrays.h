#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1);
        vector<int> dp1(n), dp2(n), dp3(n);

        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + nums[i];

        dp1[k - 1] = sum[k];
        for (int i = k; i < n; i++) {
            int ksum = sum[i + 1] - sum[i + 1 - k];
            dp1[i] = std::max(dp1[i - 1], ksum);
            dp2[i] = std::max(dp2[i - 1], dp1[i - k] + ksum);
            dp3[i] = std::max(dp3[i - 1], dp2[i - k] + ksum);
        }

        int target = dp3.back();
        int lastindx = std::lower_bound(dp3.begin(), dp3.end(), target) - dp3.begin();

        target -= sum[lastindx + 1] - sum[lastindx + 1 - k];
        int secondindex = std::lower_bound(dp2.begin(), dp2.begin() + (lastindx + 1 - k), target) - dp2.begin();

        target -= sum[secondindex + 1] - sum[secondindex + 1 - k];
        int firstindex = std::lower_bound(dp1.begin(), dp1.begin() + (secondindex + 1 - k), target) - dp1.begin();

        return {firstindex + 1 - k, secondindex + 1 - k, lastindx + 1 - k};
    }
};