#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()) return 0;
        int n = prices.size();
        int profit = 0;
        if(k > n / 2){
            for(int i = 1; i < n; i++)
                if(prices[i] > prices[i - 1])
                    profit += prices[i] - prices[i - 1];
            return profit;
        }
        vector<int> keep(n), sell(n);
        keep[0] = -prices[0];
        for(int transaction = 0; transaction < k; transaction++){
            for(int i = 1; i < n; i++)
                keep[i] = max(keep[i - 1], sell[i - 1] - prices[i]);
            for(int i = 1; i < n; i++)
                sell[i] = max(sell[i - 1], keep[i - 1] + prices[i]);
        }
        return sell.back();
    }
};