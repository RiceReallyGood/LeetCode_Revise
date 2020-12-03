#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        vector<int> level;
        for(int i = 0; i < numRows; i++){
            int sz = level.size();
            level.push_back(1);
            for(int j = sz - 1; j > 0; j--){
                level[j] += level[j - 1];
            }
            ret.emplace_back(level);
        }
        return ret;
    }
};