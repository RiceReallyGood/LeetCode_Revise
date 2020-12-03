#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        sort(nums.begin(), nums.end());
        recurse(nums, 0, res);
        return res;
    }

private:
    void recurse(vector<int>& nums, int index, vector<vector<int>>& res){
        if(index == nums.size()){
            res.emplace_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++){
            if(index < i && nums[index] == nums[i])
                continue;
            swap(nums[index], nums[i]);
            recurse(nums, index + 1, res);
        }
        int temp = nums[index];
        for(int i = index; i < nums.size() - 1; i++)
            nums[i] = nums[i + 1];
        nums[nums.size() - 1] = temp;
    }
};