#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int j = 1; j < n; j++) dp[0][j] = 1;
        unordered_multimap<int,int> indices;
        indices.insert({A[0], 0});

        int res = 0;
        for(int i = 1; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                long target = 2l * long(A[i]) - long(A[j]);
                dp[i][j] = 1;
                if(target < INT_MIN || target > INT_MAX)
                    continue;
                
                auto range = indices.equal_range(target);
                for(auto it = range.first; it != range.second; it++)
                    dp[i][j] += dp[it->second][i];

                res += dp[i][j] - 1;
            }

            indices.insert({A[i], i});
        }

        return res;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int j = 1; j < n; j++) dp[0][j] = 1;
        unordered_map<int,int> indices;
        indices[A[0]] = 0;

        int res = 0;
        for(int i = 1; i < n - 1; i++){
            if(indices.find(A[i]) != indices.end()){
                for(int j = i + 1; j < n; j++)
                    dp[i][j] = dp[indices[A[i]]][j];
            }

            for(int j = i + 1; j < n; j++){
                dp[i][j]++;
                long target = 2l * long(A[i]) - long(A[j]);
                if(target < INT_MIN || target > INT_MAX)
                    continue;
                
                if(indices.find(target) != indices.end()){
                    res += dp[indices[target]][i];
                    dp[i][j] += dp[indices[target]][i];
                }
            }

            indices[A[i]] = i;
        }

        return res;
    }
};