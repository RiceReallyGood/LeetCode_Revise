#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // dp[i][j] s.substr(0, i) 与 p.substr(0, j) 的匹配
        int slen = s.length(), plen = p.length();
        vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));
        dp[0][0] = true;
        for(int j = 1; j <= plen; j++){
            if(j % 2 == 0 && p[j - 1] ==  '*')
                dp[0][j] = dp[0][j - 2];
        }

        for(int i = 1; i <= slen; i++){
            for(int j = 1; j <= plen; j++){
                if(p[j - 1] == '.' || p[j - 1] == s[i - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*'){
                    dp[i][j] = dp[i][j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                }
            }
        }
        return dp[slen][plen];
    }
};


//reduce space
class Solution {
public:
    bool isMatch(string s, string p) {
        //上个版本的省内存版本
        int slen = s.length(), plen = p.length();
        vector<bool> dp_curr(plen + 1, false), dp_prev(plen + 1, false);
        dp_curr[0] = true;
        for(int j = 1; j <= plen; j++){
            if(j % 2 == 0 && p[j - 1] == '*')
                dp_curr[j] = dp_curr[j - 2];
        }

        for(int i = 1; i <= slen; i++){
            swap(dp_curr, dp_prev);
            dp_curr[0] = false;
            for(int j = 1; j <= plen; j++){
                if(p[j - 1] == '.' || p[j - 1] == s[i - 1])
                    dp_curr[j] = dp_prev[j - 1];
                else if(p[j - 1] == '*'){
                    dp_curr[j] = dp_curr[j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp_prev[j]);
                }
                else
                    dp_curr[j] = false;
            }
        }
        return dp_curr[plen];
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        // dp[i][j] p.substr(0, i) 与 s.substr(0, j) 的匹配
        int slen = s.length(), plen = p.length();
        vector<vector<bool>> dp(plen + 1, vector<bool>(slen + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= plen; i++){
            if(i % 2 == 0 && p[i - 1] == '*')
                dp[i][0] = dp[i - 2][0];
        }

        for(int i = 1; i <= plen; i++){
            if(p[i - 1] == '*'){
                for(int j = 1; j <= slen; j++){
                    dp[i][j] = dp[i - 2][j] || ((p[i - 2] == s[j - 1] || p[i - 2] == '.') && dp[i][j - 1]);
                }
            }
            else if(p[i - 1] == '.'){
                for(int j = 1; j <= slen; j++)
                    dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                for(int j = 1; j <= slen; j++)
                    dp[i][j] = p[i - 1] == s[j - 1] && dp[i - 1][j - 1];
            }
        }
        return dp[plen][slen];
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        // dp[i][j] p.substr(0, i) 与 s.substr(0, j) 的匹配
        int slen = s.length(), plen = p.length();
        vector<bool> dp_curr(slen + 1, false), dp_prev(slen + 1, false);
        dp_prev[0] = true;

        for(int i = 1; i <= plen; i++){
            if(p[i - 1] == '*'){
                for(int j = 1; j <= slen; j++){
                    dp_curr[j] = dp_curr[j] || ((p[i - 2] == s[j - 1] || p[i - 2] == '.') && dp_curr[j - 1]);
                }
            }
            else if(p[i - 1] == '.'){
                dp_curr[0] = false;
                for(int j = 1; j <= slen; j++)
                    dp_curr[j] = dp_prev[j - 1];
            }
            else{
                dp_curr[0] = false;
                for(int j = 1; j <= slen; j++)
                    dp_curr[j] = p[i - 1] == s[j - 1] && dp_prev[j - 1];
            }
            swap(dp_curr, dp_prev);
        }
        return dp_prev[slen];
    }
};