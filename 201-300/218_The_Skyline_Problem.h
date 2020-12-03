#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> points;
        for(auto& v : buildings){
            points.push_back(make_pair(v[0], -v[2]));
            points.push_back(make_pair(v[1], v[2]));
        }
        sort(points.begin(), points.end());
        int h = 0;
        multiset<int> hset = {0};

        vector<vector<int>> ret;
        for(int i = 0; i < points.size(); i++){
            if(points[i].second < 0)
                hset.insert(-points[i].second);
            else
                hset.erase(hset.find(points[i].second));
            
            int maxheight = *hset.rbegin();
            if(h != maxheight){
                h = maxheight;
                ret.push_back({points[i].first, h});
            }
        }
        return ret;
    }
};