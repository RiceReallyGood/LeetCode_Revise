#include <vector>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.empty()) return 0;
        int n = nums.size();
        this->lower = lower, this->upper = upper;
        vector<long> prefixsum(n + 1);
        for(int i = 0; i < n; i++)
            prefixsum[i + 1] = prefixsum[i] + nums[i];
        
        vector<long> temp(n + 1);
        return MergeAndCount(prefixsum, temp, 0, n);
    }

private:
    int lower, upper;
    int MergeAndCount(vector<long>& prefixsum, vector<long>& temp,int l, int r){
        if(l == r) return 0;

        int ret = 0;
        int c = l + (r - l) / 2;
        ret += MergeAndCount(prefixsum, temp, l, c);
        ret += MergeAndCount(prefixsum, temp, c + 1, r);

        int lb = l, ub = l;
        for(int i = c + 1; i <= r; i++){
            while(lb <= c && prefixsum[i] - prefixsum[lb] > upper) lb++;
            while(ub <= c && prefixsum[i] - prefixsum[ub] >= lower) ub++;
            ret += ub - lb;
        }

        int i = l, j = c + 1;
        for(int k = l; k <= r; k++){
            if(i > c){
                temp[k] = prefixsum[j++];
            }
            else if(j > r){
                temp[k] = prefixsum[i++];
            }
            else if(prefixsum[i] <= prefixsum[j]){
                temp[k] = prefixsum[i++];
            }
            else{
                temp[k] = prefixsum[j++];
            }
        }

        for(int k = l; k <= r; k++)
            prefixsum[i] = temp[i];
        return ret;
    }
};