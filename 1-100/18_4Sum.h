#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        vector<vector<int>> ret;
        for(int i = 0; i < sz - 3; i++){
            for(int j = i + 1; j < sz - 2; j++){
                int k = j + 1, l = sz - 1;
                int twosum = nums[i] + nums[j];
                while(k < l){
                    int foursum = twosum + nums[k] + nums[l];
                    if(foursum < target)
                        k++;
                    else if(foursum > target)
                        l--;
                    else{
                        ret.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while(k < l && nums[k] == nums[k + 1]) k++;
                        k++;
                        while(k < l && nums[l - 1] == nums[l]) l--;
                        l--;
                    }
                }
                while(j < sz - 1 && nums[j] == nums[j + 1]) j++;
            }
            while(i < sz - 1 && nums[i] == nums[i + 1]) i++;
        }
        return ret;
    }
};