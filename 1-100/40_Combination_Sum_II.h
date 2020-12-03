#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> res;
        recurse(candidates, 0, path, target, res);
        return res;
    }

private:
    void recurse(vector<int>& candidates, int index, vector<int>& path, int target, vector<vector<int>>& res){
        if(target == 0){
            res.push_back(path);
            return;
        }
        if(index == candidates.size() || candidates[index] > target) return;

        path.push_back(candidates[index]);
        recurse(candidates, index + 1, path, target - candidates[index], res);
        path.pop_back();

        while(index + 1 < candidates.size() && candidates[index + 1] == candidates[index])
            index++;
        index++;
        recurse(candidates, index, path, target, res);
    }
};