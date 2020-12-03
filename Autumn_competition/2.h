#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        int mod = 1e9 + 7;
        int res = 0;
        sort(drinks.begin(), drinks.end());
        for(int i = 0; i < staple.size(); i++){
            int target = x - staple[i];
            int count = upper_bound(drinks.begin(), drinks.end(), target) - drinks.begin();
            res = (res + count) % mod;
        }
        return res;
    }
};