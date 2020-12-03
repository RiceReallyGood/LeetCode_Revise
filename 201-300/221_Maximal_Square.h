#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int maxl = 0;
        vector<int> h(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '0') h[j] = 0;
                else h[j]++;
                
                int minh = h[j];
                for(int k = j; k >= 0; k--){
                    minh = min(minh, h[k]);
                    if(minh < j - k + 1) break;
                    maxl = max(maxl, j - k + 1);
                }
            }
        }
        return maxl * maxl;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int maxl = 0;
        vector<int> h(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '0') h[j] = 0;
                else h[j]++;
            }


            stack<int> S;
            S.push(-1);
            for(int j = 0; j < n; j++){
                while(S.top() != -1 && h[S.top()] >= h[j]){
                    int height = h[S.top()];
                    S.pop();
                    maxl = max(maxl, min(j - S.top() - 1, height));
                }
                S.push(j);
            }

            while(S.top() != -1){
                int height = h[S.top()];
                S.pop();
                maxl = max(maxl, min(n - S.top() - 1, height));
            }
        }
        return maxl * maxl;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int j = 0; j < n; j++)
            dp[0][j] = matrix[0][j] == '1' ? 1 : 0;

        for(int i = 1; i < m; i++){
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            for(int j = 1; j < n; j++)
                if(matrix[i][j] == '1')
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
        }

        int maxl = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                maxl = max(maxl, dp[i][j]);
            }
        }
        return maxl * maxl;
    }
};