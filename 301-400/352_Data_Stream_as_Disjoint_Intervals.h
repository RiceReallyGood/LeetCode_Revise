#include <vector>
#include <map>
using namespace std;

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {}
    
    void addNum(int val) {
        auto it = end_beg.lower_bound(val);

        if(it != end_beg.end() && it->second <= val) return;

        pair<int, int> interval(val, val);

        if(it != end_beg.end() && it->second == val + 1){
            interval.first = it->first;
            end_beg.erase(it);
        }

        it = end_beg.find(val - 1);

        if(it != end_beg.end()){
            interval.second = it->second;
            end_beg.erase(it);
        }

        end_beg.insert(interval);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;
        for(auto it = end_beg.begin(); it != end_beg.end(); it++)
            intervals.push_back({it->second, it->first});
        return intervals;
    }

private:
    map<int, int> end_beg;
};

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {}
    
    void addNum(int val) {
        int l = 0, r = intervals.size();
        while(l < r){
            int c = l + (r - l) / 2;
            if(intervals[c][1] < val)
                l = c + 1;
            else
                r = c;
        }

        if(l != intervals.size() && intervals[l][0] <= val) return;

        if(l != intervals.size() && intervals[l][0] == val + 1){
            if(l > 0 && intervals[l - 1][1] == val - 1){
                intervals[l - 1][1] = intervals[l][1];
                for(int i = l; i < intervals.size() - 1; i++)
                    intervals[i] = intervals[i + 1];
                intervals.pop_back();
            }
            else{
                intervals[l][0] = val;
            }
        }
        else{
            if(l > 0 && intervals[l - 1][1] == val - 1)
                intervals[l - 1][1] = val;
            else
                intervals.insert(intervals.begin() + l, {val, val});
        }
    }
    
    vector<vector<int>> getIntervals() { return intervals; }

private:
    vector<vector<int>> intervals;
};