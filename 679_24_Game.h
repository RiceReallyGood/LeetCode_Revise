#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> dnums(nums.begin(), nums.end());
        return Point24(dnums, 4);
    }

private:
    bool Point24(vector<double>& nums, int n){
        if(n == 1) return abs(nums[0] - 24) < 1e-6;

        vector<double> nums2(nums.begin() + 2, nums.end());
        nums2.push_back(0);

        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                nums2[n - 2] = nums[i] + nums[j];
                if(Point24(nums2, n - 1)) return true;
                nums2[n - 2] = nums[i] * nums[j];
                if(Point24(nums2, n - 1)) return true;
                nums2[n - 2] = nums[i] - nums[j];
                if(Point24(nums2, n - 1)) return true;
                nums2[n - 2] = nums[j] - nums[i];
                if(Point24(nums2, n - 1)) return true;
                if(abs(nums[j]) > 1e-6){
                    nums2[n - 2] = nums[i] / nums[j];
                    if(Point24(nums2, n - 1)) return true;
                }
                if(abs(nums[i]) > 1e-6){
                    nums2[n - 2] = nums[j] / nums[i];
                    if(Point24(nums2, n - 1)) return true;
                }
                if(j < n - 1)
                    nums2[j - 1] = nums[j];
            }
            for(int j = i; j < n - 2; j++)
                nums2[j] = nums[j + 2];
            if(i < n - 2)
                nums2[i] = nums[i];
        }
        return false;
    }
};