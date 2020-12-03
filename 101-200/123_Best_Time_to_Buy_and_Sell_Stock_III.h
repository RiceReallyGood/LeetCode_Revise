#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n = prices.size();
        vector<int> keep(n), sell(n);
        keep[0] = -prices[0];
        for(int transaction = 0; transaction < 2; transaction++){
            for(int i = 1; i < n; i++)
                keep[i] = max(keep[i - 1], sell[i - 1] - prices[i]);
            for(int i = 1; i < n; i++)
                sell[i] = max(sell[i - 1], keep[i - 1] + prices[i]);
        }
        return sell.back();
    }
};