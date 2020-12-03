#include <string>
using namespace std;

class Solution {
public:
    int minimumOperations(string leaves) {
        int len = leaves.length();
        int dp[3] = {0, len, len};
        dp[0] = leaves[0] == 'r' ? 0 : 1;
        for(int i = 1; i < len; i++){
            if(leaves[i] == 'r'){
                dp[2] = min(dp[1], dp[2]);
                dp[1] = 1 + min(dp[0], dp[1]);
            }
            else{
                dp[2] = 1 + min(dp[1], dp[2]);
                dp[1] = min(dp[0], dp[1]);
                dp[0] = 1 + dp[0];
            }
        }
        return dp[2];
    }
};