#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int minvol = 0, minindex = 0;
        int vol = 0;
        for(int i = 1; i < n; i++){
            vol += gas[i - 1] - cost[i - 1];
            if(vol < minvol){
                minvol = vol;
                minindex = i;
            }
        }
        vol += gas[n - 1] - cost[n - 1];
        if(vol < 0) return -1;
        return minindex;
    }
};