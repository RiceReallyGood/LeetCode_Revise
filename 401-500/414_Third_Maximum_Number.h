#include <vector>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> max3 = {nums[0]};

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > max3[0]){
                max3.insert(max3.begin(), nums[i]);
            }
            else if(nums[i] == max3[0]){
                continue;
            }
            else{
                if(max3.size() < 2){
                    max3.push_back(nums[i]);
                }
                else if(nums[i] > max3[1]){
                    max3.insert(max3.begin() + 1, nums[i]);
                }
                else if(nums[i] == max3[1]){
                    continue;
                }
                else{
                    if(max3.size() < 3){
                        max3.push_back(nums[i]);
                    }
                    else if(nums[i] > max3[2]){
                        max3.insert(max3.begin() + 2, nums[i]);
                    }
                }
            }

            if(max3.size() > 3) max3.pop_back();
        }
        if(max3.size() < 3) return max3[0];

        return max3[2];
    }
};