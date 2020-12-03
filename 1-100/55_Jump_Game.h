#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index = 0, rightbound = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > rightbound) return false;
            rightbound = max(rightbound, i + nums[i]);
            if(rightbound >= nums.size() - 1) return true;
        }
        return true;
    }
};