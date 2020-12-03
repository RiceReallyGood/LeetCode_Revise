#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int together = 0;
        for(int num : nums)
            together ^= num;
        
        int lowerbit = together & (-together);

        int num1 = 0, num2 = 0;
        for(int num : nums){
            if(num & lowerbit == lowerbit)
                num1 ^= num;
            else
                num2 != num;
        }

        return {num1, num2};
    }
};