#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = 0;
        sort(heaters.begin(), heaters.end());

        for(int i = 0; i < houses.size(); i++){
            int index = upper_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();
            int dist = INT_MAX;
            if(index < heaters.size()) dist = min(dist, heaters[index] - houses[i]);
            if(index > 0) dist = min(dist, houses[i] - heaters[index - 1]);
            res = max(res, dist);
        }
        return res;
    }
};