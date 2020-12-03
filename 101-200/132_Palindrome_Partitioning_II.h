#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        if(s.empty()) return 0;
        int len = s.length();
        vector<vector<bool>> ispalindrome(len, vector<bool>(len));
        for(int i = 0; i < len; i++)
            ispalindrome[i][i] = true;
        for(int i = 0; i < len - 1; i++)
            ispalindrome[i][i + 1] = (s[i] == s[i + 1]);
        
        for(int l = 3; l <= len; l++){
            for(int i = 0; i + l <= len; i++){
                int j = i + l - 1;
                ispalindrome[i][j] = ispalindrome[i + 1][j - 1] && s[i] == s[j];
            }
        }

        vector<int> dp(len, len);
        for(int i = 0; i < len; i++){
            if(ispalindrome[0][i]){
                dp[i] = 0;
                continue;
            }
            for(int j = 1; j <= i; j++){
                if(ispalindrome[j][i]){
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[len - 1];
    }
};