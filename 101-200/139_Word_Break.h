#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(), wordDict.end());
        int len = s.length();
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for(int i = 0; i < len; i++){
            for(int j = i; j >= 0; j--){
                if(dp[j] && wordset.find(s.substr(j, i - j + 1)) != wordset.end()){
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};