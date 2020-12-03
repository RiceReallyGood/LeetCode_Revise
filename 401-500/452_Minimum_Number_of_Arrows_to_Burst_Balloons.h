#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        auto comp = [](const vector<int>& v1, const vector<int>& v2){
            return v1[1] < v2[1];
        };

        sort(points.begin(), points.end(), comp);

        int rightbound = points[0][1];
        int res = 1;

        for(int i = 1; i < points.size(); i++){
            if(points[i][0] <= rightbound) continue;

            rightbound = points[i][1];
            res++;
        }
        return res;
    }
};