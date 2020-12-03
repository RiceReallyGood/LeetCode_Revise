#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2) return;

        int sz = nums.size();
        int index = sz - 2;
        while(index >= 0 && nums[index] >= nums[index + 1])
            index--;
        if(index >= 0){
            int tochange = nums.size() - 1;
            while(nums[index] >= nums[tochange])
                tochange--;
            swap(nums[index], nums[tochange]);
        }
        reverse(nums.begin() + index + 1, nums.end());
    }
};