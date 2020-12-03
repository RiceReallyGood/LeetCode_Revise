#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        static vector<int> dp = {0, 0, 1, 2, 4, 6, 9};
        int sz = dp.size();
        for(int i = sz; i <= n; i++){
            dp.push_back(max(dp[i - 2] * 2, dp[i - 3] * 3));
        }
        return dp[n];
    }
};

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp = {0, 0, 1, 2, 4, 6, 9};
        int sz = dp.size();
        for(int i = sz; i <= n; i++){
            dp.push_back(max(dp[i - 2] * 2, dp[i - 3] * 3));
        }
        return dp[n];
    }
};