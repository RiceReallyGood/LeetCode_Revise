#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n > 45 || n < k * (k + 1) / 2) return {};
        vector<vector<int>> ret;
        vector<int> path;
        backtrace(1, k, n, path, ret);
        return ret;
    }

private:
    void backtrace(int start, int k, int target, vector<int>& path, vector<vector<int>>& res){
        if(path.size() == k){
            if(target == 0)
                res.emplace_back(path);
            return;
        }

        for(int i = start; i < 10 && i <= target; i++){
            path.push_back(i);
            backtrace(i + 1, k, target - i, path, res);
            path.pop_back();
        }
    }
};