#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> rightbounds;

        for(int i = 0; i < intervals.size(); i++){
            if(i > 0 && intervals[i][0] == intervals[i - 1][0])
                continue;
            
            auto it = upper_bound(rightbounds.begin(), rightbounds.end(), intervals[i][0]);
            if(it == rightbounds.end())
                rightbounds.push_back(intervals[i][1]);
            else if(*it > intervals[i][1])
                *it = intervals[i][1];
        }

        return intervals.size() - rightbounds.size();
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        auto comp = [](const vector<int>& v1, const vector<int>& v2){
            return v1[1] < v2[1];
        };
        sort(intervals.begin(), intervals.end(), comp);

        int res = 1, rightbound = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < rightbound)
                res++;
            else
                rightbound = intervals[i][1];
        }

        return res;
    }
};