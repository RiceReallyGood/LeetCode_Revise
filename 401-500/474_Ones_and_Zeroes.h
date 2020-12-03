#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) { //172 ms
        vector<vector<int>> dp(m + 1 , vector<int>(n + 1, 0));

        for(auto& str : strs){
            int ones = 0, zeros = 0;
            for(char c : str){
                if(c == '0') zeros++;
                else ones++;
            }

            for(int i = m; i >= zeros; i--){
                for(int j = n; j >= ones; j--){
                    if(dp[i - zeros][j - ones] != 0){
                        dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                    }
                }
            }
            if(zeros <= m && ones <= n)
                dp[zeros][ones] = max(dp[zeros][ones], 1);
        }

        int res = 0;
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) { //304 ms
        vector<vector<int>> dp(m + 1 , vector<int>(n + 1, 0));

        for(auto& str : strs){
            int ones = 0, zeros = 0;
            for(char c : str){
                if(c == '0') zeros++;
                else ones++;
            }

            for(int i = m; i >= zeros; i--){
                for(int j = n; j >= ones; j--){
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<int>> dp(m + 1 , vector<int>(n + 1, 0));
        vector<int> zeros(sz, 0), ones(sz, 0);

        for(int i = 0; i < sz; i++) {
            for(char c : strs[i]){
                if(c == '0') zeros[i]++;
                else ones[i]++;
            }
        }

        for(int b = 0; b < sz; b++){
            for(int i = m; i >= zeros[b]; i--){
                for(int j = n; j >= ones[b]; j--){
                    if(dp[i - zeros[b]][j - ones[b]] != 0){
                        dp[i][j] = max(dp[i][j], dp[i - zeros[b]][j - ones[b]] + 1);
                    }
                }
            }
            if(zeros[b] <= m && ones[b] <= n)
                dp[zeros[b]][ones[b]] = max(dp[zeros[b]][ones[b]], 1);
        }

        int res = 0;
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};