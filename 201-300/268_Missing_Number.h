#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int index = 0;

        while(index < nums.size()){
            if(nums[index] == n || nums[index] == index)
                index++;
            else{
                swap(nums[index], nums[nums[index]]);
            }
        }

        for(int i = 0; i < n; i++)
            if(nums[i] != i)
                return i;
        return n;
    }
};