#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        static string next = "bcdefghijklmnopqrstuvwxyza";
        if(p.empty()) return 0;
        vector<int> dp(26, 0);
        dp[p[0] - 'a'] = 1;
        int len = 1;
        for(int i = 1; i < p.length(); i++){
            if(p[i] == next[p[i - 1] - 'a']){
                len++;
            }
            else{
                len = 1;
            }
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], len);
        }
        int res = 0;
        for(int i = 0; i <26; i++)
            res += dp[i];
        return res;
    }
};