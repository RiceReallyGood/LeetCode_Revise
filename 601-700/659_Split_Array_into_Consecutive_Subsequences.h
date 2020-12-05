#include <climits>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> seqs;

        for (int num : nums) {
            if (num == INT_MIN || seqs.find(num - 1) == seqs.end()) {
                seqs[num].push(1);
            }
            else {
                int len = seqs[num - 1].top();
                seqs[num - 1].pop();
                if (seqs[num - 1].empty()) seqs.erase(num - 1);
                seqs[num].push(len + 1);
            }
        }

        for (auto it : seqs) {
            if (it.second.top() < 3)
                return false;
        }

        return true;
    }
};

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> count;
        unordered_map<int, int> endcount;

        for (int num : nums)
            count[num]++;

        for (int num : nums) {
            if (count.find(num) == count.end())
                continue;

            if (--count[num] == 0)
                count.erase(num);

            if (num == INT_MIN || endcount.find(num - 1) == endcount.end()) {
                if (num > INT_MAX - 2 || count.find(num + 1) == count.end() || count.find(num + 2) == count.end())
                    return false;
                if (--count[num + 1] == 0) count.erase(num + 1);
                if (--count[num + 2] == 0) count.erase(num + 2);
                endcount[num + 2]++;
            }
            else {
                if (--endcount[num - 1] == 0)
                    endcount.erase(num - 1);
                endcount[num]++;
            }
        }

        return true;
    }
};