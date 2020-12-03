#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int translateNum(int num) {
        if(num == 0) return 1;
        vector<int> digits;
        while(num){
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());
        int len = digits.size();
        vector<int> dp(len + 1);
        dp[0] = 1, dp[1] = 1;
        for(int i = 1; i < len; i++){
            dp[i + 1] = dp[i];
            if(digits[i - 1] > 0 && digits[i - 1] * 10 + digits[i] < 26) dp[i + 1] += dp[i - 1];
        }
        return dp.back();
    }
};