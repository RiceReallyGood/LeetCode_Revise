#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = int(nums.size()) - 1;

        while(l < r){
            if(nums[l] < nums[r]) return nums[l];
            if(nums[l] == nums[r]){
                l++;
                continue;
            }
            int c = l + (r - l) / 2;
            if(nums[c] >= nums[l])
                l = c + 1;
            else
                r = c;
        }
        return nums[l];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = int(nums.size()) - 1;

        while(l < r){
            if(nums[l] == nums[r]){
                r--;
            }
            else{
                int c = l + (r - l) / 2;
                if(nums[c] <= nums[r])
                    r = c;
                else
                    l = c + 1;
            }
        }
        return nums[l];
    }
};