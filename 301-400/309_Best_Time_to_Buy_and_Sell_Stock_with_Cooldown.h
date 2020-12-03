#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        vector<int> keep(n), sell(n);
        keep[0] = -prices[0], keep[1] = max(keep[0], -prices[1]);
        sell[1] = max(0, prices[1] - prices[0]);
        for(int i = 2; i < n; i++){
            keep[i] = max(keep[i -1], sell[i - 2] - prices[i]);
            sell[i] = max(sell[i - 1], keep[i - 1] + prices[i]);
        }
        return sell.back();
    }
};