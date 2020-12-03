#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> seq;

        recurse(nums, 0, seq, res);
        return res;
    }

private:
    void recurse(vector<int>& nums, int index, vector<int>& seq, vector<vector<int>>& res){
        if(seq.size() >= 2) res.push_back(seq);
        if(index == nums.size()) return;

        vector<bool> skiped(201, false);
        for(int i = index; i < nums.size(); i++){
            if((!seq.empty() && seq.back() > nums[i]) || skiped[nums[i] + 100])
                continue;
            
            seq.push_back(nums[i]);
            recurse(nums, i + 1, seq, res);
            seq.pop_back();
            skiped[nums[i] + 100] = true;
        }
    }
};