#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int c = l + (r - l) / 2;
            if(nums[c] > nums[c + 1])
                r = c;
            else
                l = c + 1;
        }
        return l;
    }
};