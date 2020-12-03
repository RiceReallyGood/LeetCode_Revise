#include <vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long rightbound = 0;
        int count = 0;
        int index = 0;
        while(rightbound < n){
            if(index < nums.size() && nums[index] <= rightbound + 1)
                rightbound += nums[index++];
            else{
                rightbound += rightbound + 1;
                count++;
            }
        }
        return count;
    }
};