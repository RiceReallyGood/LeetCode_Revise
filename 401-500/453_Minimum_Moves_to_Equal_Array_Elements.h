#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minele = *min_element(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
            res += nums[i] - minele;
        
        return res;
    }
};