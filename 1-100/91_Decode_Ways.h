#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for(int i = 2; i <= s.length(); i++){
            if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7'))
                dp[i] += dp[i - 2];
            if(s[i - 1] != '0')
                dp[i] += dp[i - 1];
        }
        return dp[s.length()];
    }
};