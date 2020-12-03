#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.empty()) return false;
        this->target = 0;
        for(int num : nums) this->target += num;
        if(this->target % 4 != 0) return false;
        this->target /= 4;

        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> accum(4, 0);

        return recurse(nums, 0, accum);
    }

private:
    int target;
    bool recurse(vector<int>& nums, int index, vector<int>& accum){
        if(index == nums.size()) return true;

        for(int i = 0; i < 4; i++){
            if(nums[index] + accum[i] <= target){
                bool seenBefore = false;
                for(int j = 0; j < i; j++){
                    if(accum[j] == accum[i]){
                        seenBefore = true;
                        break;
                    }
                }
                if(seenBefore) continue;
                accum[i] += nums[index];
                if(recurse(nums, index + 1, accum))
                    return true;
                accum[i] -= nums[index];
            }
            if(accum[i] == 0) break;
        }

        return false;
    }
};