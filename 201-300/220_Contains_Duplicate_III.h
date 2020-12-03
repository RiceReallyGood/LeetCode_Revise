#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> prevk;
        for(int i = 0; i < nums.size(); i++){
            if(prevk.lower_bound(nums[i] - t) != prevk.upper_bound(nums[i] + t))
                return true;
            
            prevk.insert(nums[i]);

            if(i >= k)
                prevk.erase(nums[i - k]);
        }
        return false;
    }
};