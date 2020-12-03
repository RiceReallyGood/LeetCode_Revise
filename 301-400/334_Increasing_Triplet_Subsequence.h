#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > b) return true;
            if(nums[i] <= a) a = nums[i];
            else b = nums[i];
        }
        return false;
    }
};