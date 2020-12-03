#include <vector>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        vector<long> lnums(nums.begin(), nums.end());
        vector<long> aux(n);
        return MergeAndCount(lnums, aux, 0, n - 1);
    }

private:
    int MergeAndCount(vector<long>& nums, vector<long>& aux,int l, int r){
        if(l == r) return 0;
        int c = l + (r - l) / 2;
        int ret = 0;
        ret += MergeAndCount(nums, aux, l, c);
        ret += MergeAndCount(nums, aux, c + 1, r);

        int i = l, j = c + 1, lb = c + 1;
        for(int k = l; k <= r; k++){
            if(i > c){
                aux[k] = nums[j++];
            }
            else if(j > r){
                while(lb <= r && nums[lb] * 2 < nums[i]) lb++;
                aux[k] = nums[i++];
                ret += lb - c - 1;
            }
            else if(nums[i] <= nums[j]){
                while(lb <= r && nums[lb] * 2 < nums[i]) lb++;
                aux[k] = nums[i++];
                ret += lb - c - 1;
            }
            else{
                aux[k] = nums[j++];
            }
        }

        for(int k = l; k <= r; k++)
            nums[k] = aux[k];
        return ret;
    }
};