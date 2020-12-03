#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int target = 0;
        for(int num : nums)
            target ^= num;
        return target;
    }
};