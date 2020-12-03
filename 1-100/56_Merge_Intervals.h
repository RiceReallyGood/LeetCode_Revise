#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        int index = 0;
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[index][1] >= intervals[i][0])
                intervals[index][1] = max(intervals[index][1], intervals[i][1]);
            else
                intervals[++index] = intervals[i];
        }
        intervals.resize(index + 1);
        return intervals;
    }

private:
    class comp{
    public:
        bool operator()(vector<int>& v1, vector<int>& v2){
            if(v1[0] < v2[0]) return true;
            else if(v1[0] > v2[0]) return false;
            else return v1[1] < v2[1];
        }
    };
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        ret.emplace_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(ret.back()[1] >= intervals[i][0])
                ret.back()[1] = max(ret.back()[1], intervals[i][1]);
            else
                ret.emplace_back(intervals[i]);
        }
        return ret;
    }
};