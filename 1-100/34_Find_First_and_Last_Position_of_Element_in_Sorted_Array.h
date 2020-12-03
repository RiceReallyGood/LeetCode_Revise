#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //lowerbound
        int l = 0, r = nums.size();
        while(l < r){
            int c = l + (r - l) / 2;
            if(nums[c] < target)
                l = c + 1;
            else
                r = c;
        }
        int lowerbound = l;

        //upperbound
        l = 0, r = nums.size();
        while(l < r){
            int c = l + (r - l) / 2;
            if(nums[c] <= target)
                l = c + 1;
            else
                r = c;
        }
        int upperbound = l;
        if(lowerbound == upperbound)
            return {-1, -1};
        return {lowerbound, upperbound - 1};
    }
};