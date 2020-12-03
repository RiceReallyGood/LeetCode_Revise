#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= target; i++){
            int k = 0, temp = i;
            while(temp){
                k++;
                temp >>= 1;
            }

            if(i == (1 << k) - 1){
                dp[i] = k;
            }
            else{
                for(int j = 0; j < k; j++){
                    dp[i] = min(dp[i], k + j + 1 + dp[i - (1 << (k - 1)) + (1 << j)]);
                }
                dp[i] = min(dp[i], k + 1 + dp[(1 << k) - 1 - i]);
            }
        }
        return dp[target];
    }
};