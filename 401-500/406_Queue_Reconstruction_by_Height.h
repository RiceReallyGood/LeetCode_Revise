#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto comp = [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] == v2[0] ? v1[1] > v2[1] : v1[0] < v2[0];
        };
        int n = people.size();
        sort(people.begin(), people.end(), comp);
        BinaryIndexTree bit(n);

        vector<vector<int>> ret(n);
        for(int i = 0; i < n; i++){
            int order = people[i][1];

            int l = 0, r = n;
            while(l < r){
                int c = l + (r - l) / 2;
                if(c - bit.sum(c) < order) l = c + 1;
                else r = c;
            }

            ret[l] = people[i];
            bit.add(l, 1);
        }
        return ret;
    }

private:
    class BinaryIndexTree{
    public:
        BinaryIndexTree(int n_) : n(n_), partialsum(n_ + 1) {}
        BinaryIndexTree(std::vector<int>& data) : n(data.size()), partialsum(data.size() + 1) {
            for(int i = 0; i < n; i++) add(i, data[i]);
        }

        void add(int i, int val){
            for(int idx = i + 1; idx <= n; idx += (idx & (-idx))){
                partialsum[idx] += val;
            }
        }

        int sum(int i){
            int ret = 0;
            for(int idx = i + 1; idx > 0; idx -= (idx & (-idx))){
                ret += partialsum[idx];
            }
            return ret;
        }
    private:
        int n;
        std::vector<int> partialsum;
    };
};