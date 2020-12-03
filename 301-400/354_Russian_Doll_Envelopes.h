#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        auto comp = [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] < v2[0] ? true : v1[0] > v2[0] ? false : v1[1] > v2[1];
        };
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> minheight;
        for(auto & e : envelopes){
            auto it = lower_bound(minheight.begin(), minheight.end(),e[1]);
            if(it == minheight.end())
                minheight.push_back(e[1]);
            else
                *it = e[1];
        }
        return minheight.size();
    }
};