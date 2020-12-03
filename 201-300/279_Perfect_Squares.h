#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> mincount(n + 1, n);
        mincount[0] = 0;

        vector<int> squares;
        for(int i = 1; i * i <= n; i++)
            squares.push_back(i * i);
        if(squares.back() == n) return 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0;j < squares.size() && i - squares[j] >= 0; j++){
                mincount[i] = min(mincount[i], mincount[i - squares[j]] + 1);
            }
        }

        return mincount[n];
    }
};

class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp {0};
        int m = dp.size();
        dp.resize(max(m, n + 1), INT_MAX);
        for(int i = 1, i2; (i2 = i * i) <= n; ++i)
            for(int j = max(m, i2); j <= n; ++j)
                dp[j] = min(dp[j], dp[j - i2] + 1);
        return dp[n];
    }
};