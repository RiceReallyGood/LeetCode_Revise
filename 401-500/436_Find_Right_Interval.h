#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int,int>> start_index;
        for(int i = 0; i < intervals.size(); i++){
            start_index.push_back({intervals[i][0], i});
        }
        sort(start_index.begin(), start_index.end());

        vector<int> ret(intervals.size());
        for(int i = 0; i < intervals.size(); i++){
            auto it = lower_bound(start_index.begin(), start_index.end(), make_pair(intervals[i][1], -1));
            if(it == start_index.end())
                ret[i] = -1;
            else
                ret[i] = it->second;
        }
        return ret;
    }
};