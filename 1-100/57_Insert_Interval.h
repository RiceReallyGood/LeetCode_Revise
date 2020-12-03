#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int index = 0;
        while(index < intervals.size() && intervals[index][1] < newInterval[0])
            ret.emplace_back(intervals[index++]);
        
        int left = newInterval[0], right = newInterval[1];
        if(index < intervals.size()) left = min(left, intervals[index][0]);
        while(index < intervals.size() && intervals[index][0] <= right)
            right = max(right, intervals[index++][1]);
        ret.push_back({left, right});
        while(index < intervals.size())
            ret.emplace_back(intervals[index++]);
        return ret;
    }
};