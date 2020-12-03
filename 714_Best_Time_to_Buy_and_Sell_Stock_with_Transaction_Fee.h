#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() < 2) return 0;
        int n = prices.size();
        vector<int> keep(n), sell(n);
        keep[0] = -prices[0] - fee;
        for(int i = 1; i < n; i++){
            keep[i] = max(keep[i - 1], sell[i - 1] -prices[i] - fee);
            sell[i] = max(sell[i - 1], keep[i - 1] + prices[i]);
        }
        return sell.back();
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() < 2) return 0;
        int n = prices.size();
        int keep = -prices[0] -fee, sell = 0;
        for(int i = 1; i < n; i++){
            keep = max(keep, sell - prices[i] - fee);
            sell = max(sell, keep + prices[i]);
        }
        return sell;
    }
};