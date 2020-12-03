#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while(nums[nums[i] - 1] != nums[i]){
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        vector<int> ret;
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1)
                ret.push_back(nums[i]);
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        for(int num : nums){
            if(nums[std::abs(num) - 1] > 0)
                nums[std::abs(num) - 1] *= -1;
            else
                ret.push_back(std::abs(num));
        }
        return ret;
    }
};