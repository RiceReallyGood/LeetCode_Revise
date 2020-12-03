#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        for(int i = 0; i <= nums.size(); i++){
            recurse(i, 0, path, nums, res);
        }
        return res;
    }

private:
    void recurse(int sz, int index, vector<int>& path, vector<int>& nums, vector<vector<int>>& res){
        if(path.size() == sz){
            res.emplace_back(path);
            return;
        }
        
        for(int i = index; i <= nums.size() - (sz - path.size()); i++){
            path.push_back(nums[i]);
            recurse(sz, i + 1, path, nums, res);
            path.pop_back();
        }
    }
};