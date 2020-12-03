#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty()) return 0;

        int index = 1;
        while(index < nums.size() && nums[index] == nums[index - 1]) index++;

        if(index == nums.size()) return 1;

        int ret = 2;
        bool increase = nums[index] > nums[index - 1];

        for(int i = index + 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]) continue;

            if(nums[i] > nums[i - 1]){
                if(!increase){
                    increase = true;
                    ret++;
                }
            }
            else{
                if(increase){
                    increase = false;
                    ret++;
                }
            }
        }
        return ret;
    }
};