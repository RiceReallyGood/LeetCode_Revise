#include <vector>
using namespace std;

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        if(boardingCost * 4 <= runningCost) return -1;

        int sum = 0;
        for(int num : customers) sum += num;

        if(sum < 4 && sum * boardingCost <= runningCost) return -1;

        int res = sum / 4;

        sum %= 4;
        if(sum * boardingCost - runningCost > 0)
            res++;
        
        return res;
    }
};