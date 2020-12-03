#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = 0;
        int sum = 0;
        int ret = nums.size() + 1;
        while(j < nums.size()){
            while(j <  nums.size() && sum < s)
                sum += nums[j++];
            
            while(sum >= s){
                ret = min(ret, j - i);
                sum -= nums[i++];
            }
        }
        return ret > nums.size() ? 0 : ret;
    }
};