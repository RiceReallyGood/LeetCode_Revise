#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26);
        for (char c : tasks) count[c - 'A']++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq1;
        priority_queue<pair<int, int>> pq2;

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0)
                pq1.push({1, i});
            count[i]--;
        }

        int res = 0;
        while (!pq1.empty() || !pq2.empty()) {
            res = pq2.empty() ? pq1.top().first : res + 1;

            while (!pq1.empty() && pq1.top().first <= res) {
                auto node = pq1.top();
                pq1.pop();
                pq2.push({count[node.second], node.second});
            }

            auto node = pq2.top();
            pq2.pop();
            if (count[node.second] != 0) {
                pq1.push({res + n + 1, node.second});
                count[node.second]--;
            }
        }

        return res;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        vector<int> count(26);
        for (char c : tasks) count[c - 'A']++;

        int maxele = *max_element(count.begin(), count.end());
        int maxcnt = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] == maxele)
                maxcnt++;
        }

        return max(len, (n + 1) * (maxele - 1) + maxcnt);
    }
};