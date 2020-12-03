#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int N = Profits.size();
        vector<pair<int, int>> cps;
        for (int i = 0; i < N; i++)
            cps.push_back({Capital[i], Profits[i]});

        sort(cps.begin(), cps.end());

        int proj = 0;
        priority_queue<int> pq;
        for (int i = 0; i < k; i++) {
            while (proj < N && cps[proj].first <= W)
                pq.push(cps[proj++].second);

            if (pq.empty()) return W;

            W += pq.top();
            pq.pop();
        }

        return W;
    }
};