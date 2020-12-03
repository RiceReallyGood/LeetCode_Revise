#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int currindex = 0;
        int rightbound = 0, step = 0;
        int sz = nums.size();
        while(rightbound < sz - 1){
            int temp = currindex;
            for(int i = currindex; i <= rightbound; i++){
                temp = max(temp, nums[i] + i);
            }
            currindex = rightbound + 1;
            rightbound = temp;
            step++;
        }
        return step;
    }
};