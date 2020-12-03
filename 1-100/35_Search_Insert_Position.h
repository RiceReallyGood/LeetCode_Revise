#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(!nums.empty() && nums.back() < target)
            return nums.size();
        int l = 0, r = nums.size();
        while(l < r){
            int c = l + (r - l) / 2;
            if(nums[c] < target)
                l = c + 1;
            else
                r = c;
        }
        return l;
    }
};