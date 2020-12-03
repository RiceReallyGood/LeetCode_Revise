#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numindex;
        for(int i= 0; i < nums.size(); i++){
            int theother = target - nums[i];
            if(numindex.find(theother) != numindex.end())
                return {numindex[theother], i};
            else
                numindex[nums[i]] = i;
        }
        return {-1,-1};
    }
};