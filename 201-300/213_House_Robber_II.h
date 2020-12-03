#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int ret = 0;
        int rob = 0, unrob = 0;
        for(int i = 0; i < n - 1; i++){
            int temp = unrob;
            unrob = max(unrob, rob);
            rob = temp + nums[i];
        }
        ret = max(rob, unrob);

        rob = 0, unrob = 0;
        for(int i = 1; i < n; i++){
            int temp = unrob;
            unrob = max(unrob, rob);
            rob = temp + nums[i];
        }
        ret = max(ret, max(rob, unrob));
        return ret;
    }
};