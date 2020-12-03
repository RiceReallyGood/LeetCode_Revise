#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<vector<int>> ret;
        for(int i = 0; i <= nums.size(); i++)
            recurse(i, nums, 0, path, ret);
        return ret;
    }

private:
    void recurse(int sz, vector<int>& nums, int index, vector<int>& path, vector<vector<int>>& res){
        if(sz == path.size()){
            res.emplace_back(path);
            return;
        }

        for(int i = index; i <= nums.size() - (sz - path.size()); i++){
            if(i > index && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            recurse(sz, nums, i + 1, path, res);
            path.pop_back();
        }
    }
};