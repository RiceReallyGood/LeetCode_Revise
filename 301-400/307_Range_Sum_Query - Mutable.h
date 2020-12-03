#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) :data(nums) {
        this->n = nums.size();
        partialsum.resize(n + 1, 0);
        for(int i = 0; i < n; i++)
            add(i + 1, nums[i]);
    }
    
    void update(int i, int val) {
        add(i + 1, val - data[i]);
        data[i] = val;
    }
    
    int sumRange(int i, int j) {
        return sum(j + 1) - sum(i);
    }

private:
    int n;
    vector<int> data;
    vector<int> partialsum;
    int sum(int i){
        int ret = 0;
        for(int idx = i; idx; idx -= (idx & (-idx)))
            ret += partialsum[idx];
        return ret;
    }

    void add(int i, int val){
        for(int idx = i; idx <= n; idx += (idx & (-idx))){
            partialsum[idx] += val;
        }
    }
};