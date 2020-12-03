#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        vector<vector<int>> res;
        recurse(n, k, comb, res);
        return res;
    }

private:
    void recurse(int n, int k, vector<int>& comb, vector<vector<int>>& res){
        if(comb.size() == k){
            res.emplace_back(comb);
            return;
        }

        for(int i = comb.empty() ? 1 : comb.back() + 1; i <= n - (k - comb.size()) + 1; i++){
            comb.push_back(i);
            recurse(n, k, comb, res);
            comb.pop_back();
        }
    }
};