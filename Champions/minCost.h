#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int l = cuts.size();
        vector<vector<int>> dp(l, vector<int>(l, INT_MAX));

        for(int i = 0; i < l - 1; i++) dp[i][i + 1] = 0;

        for(int i = l - 3; i >= 0; i--){
            for(int j = i + 2; j < l; j++){
                int len = cuts[j] - cuts[i];
                for(int k = i + 1; k < j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + len);
                }
            }
        }

        return dp[0][l - 1];
    }
};