#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int take = 0, leave = 0;
        for(int i = 0; i < nums.size(); i++){
            int temp = leave;
            leave = max(leave, take);
            take = temp + nums[i];
        }
        return max(take, leave);
    }
};