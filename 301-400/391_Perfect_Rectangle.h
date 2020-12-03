#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        vector<pair<int, pair<int, int>>> left, right;
        for(int i = 0; i < rectangles.size(); i++){
            left.push_back(make_pair(rectangles[i][0], make_pair(rectangles[i][1], rectangles[i][3])));
            right.push_back(make_pair(rectangles[i][2], make_pair(rectangles[i][1], rectangles[i][3])));
        }
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        vector<vector<int>> interval;
        int index = left[0].first, lid = 0, rid = 0;
        while(lid < left.size() && left[lid].first == index){
            if(!insert(interval, {left[lid].second.first, left[lid].second.second}))
                return false;
            lid++;
        }
        if(interval.size() != 1) return false;
        int low = interval[0][0], up = interval[0][1];

        while(rid < right.size()){
            index = right[rid].first;
            if(lid < left.size() && left[lid].first < index) return false;
            while(rid < right.size() && right[rid].first == index){
                erase(interval, {right[rid].second.first, right[rid].second.second});
                rid++;
            }

            if(rid == right.size()) break;
            while(lid < left.size() && left[lid].first == index){
                if(!insert(interval, {left[lid].second.first, left[lid].second.second}))
                    return false;
                lid++;
            }

            if(interval.size() != 1 || (interval[0][0] != low || interval[0][1] != up))
                return false;
        }
        return true;
    }

private:
    bool insert(vector<vector<int>>& intervals, const vector<int>& interval){
        auto it = lower_bound(intervals.begin(), intervals.end(), interval);
        if(it != intervals.end() && (*it)[0] < interval[1]) return false;
        if(it != intervals.begin() && (*(it - 1))[1] > interval[0]) return false;

        if(it != intervals.end() && (*it)[0] == interval[1]){
            if(it != intervals.begin() && (*(it - 1))[1] == interval[0]){  
                (*(it - 1))[1] = (*it)[1];
                intervals.erase(it);
            }
            else{
                (*it)[0] = interval[0];
            }
        }
        else{
            if(it != intervals.begin() && (*(it - 1))[1] == interval[0]){  
                (*(it - 1))[1] = interval[1];
            }
            else{
                intervals.insert(it, interval);
            }
        }
        return true;
    }

    void erase(vector<vector<int>>& intervals, const vector<int>& interval){
        auto it = lower_bound(intervals.begin(), intervals.end(), interval);
        if(it != intervals.end() && (*it)[0] == interval[0]){
            if((*it)[1] == interval[1])
                intervals.erase(it);
            else
                (*it)[0] = interval[1];
        }
        else{
            --it;
            if((*it)[1] == interval[1])
                (*it)[1] = interval[0];
            else{
                vector<int> newinterval = {(*it)[0], interval[0]};
                (*it)[0] = interval[1];
                intervals.insert(it, newinterval);
            }
        }
    }
};