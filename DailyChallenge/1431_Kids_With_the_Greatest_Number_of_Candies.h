#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxcandies = *max_element(candies.begin(), candies.end());
        vector<bool> ret(candies.size(), false);
        for(int i = 0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= maxcandies)
                ret[i] = true;
        }
        return ret;
    }
};