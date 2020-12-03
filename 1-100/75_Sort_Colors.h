#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty()) return;
        int zerobound = 0, twobound = nums.size() - 1;
        for(int i = 0; i <= twobound; i++){
            if(nums[i] == 0) swap(nums[zerobound++], nums[i]);
            else if(nums[i] == 2) swap(nums[i--], nums[twobound--]);
        }
    }
};