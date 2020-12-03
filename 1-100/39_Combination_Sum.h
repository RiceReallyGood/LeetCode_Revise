#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        vector<vector<int>> res;
        recurse(candidates, 0, path, target, res);
        return res;
    }

private:
    void recurse(vector<int>& canditates, int index, vector<int>& path, int target, vector<vector<int>>& res){
        if(target == 0){
            res.push_back(path);
            return;
        }
        if(index == canditates.size()) return;

        if(canditates[index] <= target){
            path.push_back(canditates[index]);
            recurse(canditates, index, path, target - canditates[index], res);
            path.pop_back();
        }

        recurse(canditates, index + 1, path, target,res);
    }
};