#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty()) return {};
        int sz = nums.size();
        vector<int> ret(sz, 1);
        int lefttoright = 1;
        for(int i = 1; i < sz; i++){
            lefttoright *= nums[i - 1];
            ret[i] = lefttoright;
        }

        int righttoleft = 1;
        for(int i = sz - 2; i >= 0; i--){
            righttoleft *= nums[i + 1];
            ret[i] *= righttoleft;
        }
        return ret;
    }
};