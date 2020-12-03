#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int N = nums.size();
        vector<pair<int, int>> num_index;
        for (int i = 0; i < N; i++) {
            num_index.push_back(pair<int, int>(nums[i], i));
        }

        sort(num_index.begin(), num_index.end(), std::greater<pair<int, int>>());

        vector<string> res(N);
        if (N > 0) res[num_index[0].second] = "Gold Medal";
        if (N > 1) res[num_index[1].second] = "Silver Medal";
        if (N > 2) res[num_index[2].second] = "Bronze Medal";

        for (int i = 3; i < N; i++) {
            res[num_index[i].second] = to_string(i + 1);
        }

        return res;
    }
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int N = nums.size();
        vector<int> order(N);
        for(int i = 0; i < N; i++) order[i] = i;

        sort(order.begin(), order.end(), [&nums](const int& i1, const int& i2){
            return nums[i1] > nums[i2];
        });

        vector<string> res(N);
        if (N > 0) res[order[0]] = "Gold Medal";
        if (N > 1) res[order[1]] = "Silver Medal";
        if (N > 2) res[order[2]] = "Bronze Medal";

        for (int i = 3; i < N; i++) {
            res[order[i]] = to_string(i + 1);
        }

        return res;
    }
};