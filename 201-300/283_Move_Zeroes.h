#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;

        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != 0) nums[index++] = nums[j];
        }

        while(index < nums.size()) nums[index++] = 0;
    }
};