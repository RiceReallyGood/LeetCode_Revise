#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

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