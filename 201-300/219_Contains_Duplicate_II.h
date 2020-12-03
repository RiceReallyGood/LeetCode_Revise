#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastindex;
        for(int i = 0; i < nums.size(); i++){
            if(lastindex.find(nums[i]) == lastindex.end())
                lastindex[nums[i]] = i;
            else{
                if(i - lastindex[nums[i]] <= k)
                    return true;
                lastindex[nums[i]] = i;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> prevk;
        for(int i = 0; i < nums.size(); i++){
            if(prevk.find(nums[i]) != prevk.end())
                return true;
            prevk.insert(nums[i]);
            if(i >= k)
                prevk.erase(nums[i - k]);
        }
        return false;
    }
};