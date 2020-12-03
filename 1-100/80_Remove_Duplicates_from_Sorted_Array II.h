#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(index == 0 || nums[index - 1] != nums[i]){
                nums[index++] = nums[i];
                count = 1;
            }
            else if(count == 1){
                nums[index++] = nums[i];
                count++;
            }
        }
        return index;
    }
};