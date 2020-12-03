#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[2];

        int sz = nums.size();
        for(int i = 0; i < sz - 2; i++){
            if(i > 0 && nums[i - 1] == nums[i]) continue;
            int j = i + 1, k = sz - 1;
            while(j < k){
                int threesum = nums[i] + nums[j] + nums[k];
                if(threesum < target){
                    if(target - threesum < abs(target - ret))
                        ret = threesum;
                    while(j < k && nums[j] == nums[j + 1]) j++;
                    j++;
                }
                else if(threesum > target){
                    if(threesum - target < abs(target - ret))
                        ret = threesum;
                    while(j < k && nums[k - 1] == nums[k]) k--;
                    k--;
                }
                else
                    return target;
            }
            if(nums[i] + nums[i + 1] + nums[i + 2] > target)
                break;
        }
        return ret;
    }
};