#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int prevmin = prices[0];
        int maxprofit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prevmin)
                maxprofit = max(maxprofit, prices[i] - prevmin);
            else
                prevmin = prices[i];
        }
        return maxprofit;
    }
};