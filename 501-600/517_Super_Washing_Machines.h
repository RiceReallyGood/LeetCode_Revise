#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int sum = accumulate(machines.begin(), machines.end(), 0);
        if (sum % n != 0) return -1;
        int target = sum / n;

        int res = 0, flow = 0;
        for (int i = 0; i < n; i++) {
            flow += machines[i] - target;
            res = max(res, abs(flow));

            if (machines[i] > target)
                res = max(res, machines[i] - target);
        }

        return res;
    }
};