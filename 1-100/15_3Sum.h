#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        unordered_map<int,int> num_count;
        for(int num : nums) num_count[num]++;

        int sz = nums.size();
        for(int i = 0; i < sz; i++){
            if(nums[i] > 0) break;
            if(nums[i] == 0){
                if(num_count[0] >= 3)
                    ret.push_back({0,0,0});
                break;
            }
            for(int j = i + 1; j < sz; j++){
                if(nums[i] + 2 * nums[j] > 0) break;
                if(nums[i] + 2 * nums[j] == 0){
                    if(num_count[nums[j]] >= 2)
                        ret.push_back({nums[i], nums[j], nums[j]});
                    break;
                }
                int c = -(nums[i] + nums[j]);
                if(num_count.find(c) != num_count.end())
                    ret.push_back({nums[i], nums[j], c});
                while(j < sz - 1 && nums[j + 1] == nums[j])
                    j++;
            }
            while(i < sz - 1 && nums[i + 1] == nums[i])
                i++;
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

        int sz = nums.size();
        for(int i = 0; i < sz; i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = sz - 1;
            int twosum = -nums[i];
            while(j < k){
                if(nums[j] + nums[k] < twosum)
                    j++;
                else if(nums[j] + nums[k] > twosum)
                    k--;
                else{
                    ret.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j + 1]) j++;
                    j++;
                    while(j < k && nums[k - 1] == nums[k]) k--;
                    k--;
                }
            }
        }
        return ret;
    }
};