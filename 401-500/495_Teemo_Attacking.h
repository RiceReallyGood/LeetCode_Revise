#include <vector>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int rightbound = 0, res = 0;

        for(int i = 0; i < timeSeries.size(); i++){
            if(timeSeries[i] >= rightbound){
                res += duration;
            }
            else{
                res += timeSeries[i] + duration - rightbound;
            }

            rightbound = timeSeries[i] + duration;
        }

        return res;
    }
};

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty()) return 0;
        int res = 0;
        for(int i = 1; i < timeSeries.size(); i++)
            res += min(duration, timeSeries[i] - timeSeries[i - 1]);

        return res + duration;
    }
};