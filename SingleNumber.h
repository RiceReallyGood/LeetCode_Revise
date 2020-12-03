#ifndef SINGLENUMBER_H
#define SINGLENUMBER_H

#include <vector>

/* 
给定义一个数组，其中有一个数字值出现一次，而其他的数字
均出现k次(k > 1), 求这个数字。
*/

class Solution {
public:
    int singleNumber(std::vector<int>& nums, int k) {
        if(k <= 1 || nums.size() % k != 1 ) return 0;
        std::vector<int> dp(k);
        dp[0] = ~0;
        for(int num : nums){
            int temp = dp[k - 1];
            for(int i = k - 1; i > 0; i--){
                dp[i] ^= (num & dp[i]) | (num & dp[i - 1]);
            }
            dp[0] ^= (num & dp[0]) | (num & temp);
        }
        return dp[1];
    }
};

#endif //SINGLENUMBER_H