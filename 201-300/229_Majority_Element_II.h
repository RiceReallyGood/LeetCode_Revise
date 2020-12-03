#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = 0, count1 = 0;
        int num2 = 0, count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == num1)
                count1++;
            else if(nums[i] == num2)
                count2++;
            else{
                if(count1 == 0){
                    num1 = nums[i];
                    count1 = 1;
                }
                else if(count2 == 0){
                    num2 = nums[i];
                    count2 = 1;
                }
                else{
                    count1--;
                    count2--;
                }
            }
        }
        count1 = 0, count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(num1 == nums[i]) count1++;
            if(num2 == nums[i]) count2++;
        }

        vector<int> ret;
        if(count1 > nums.size() / 3) ret.push_back(num1);
        if(num2 != num1 && count2 > nums.size() / 3) ret.push_back(num2);
        return ret;
    }
};