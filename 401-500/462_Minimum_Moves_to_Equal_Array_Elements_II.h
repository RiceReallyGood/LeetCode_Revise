#include <vector>
#include <random>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        partition_3way(nums, 0, n - 1, n / 2);
        int pivot = nums[n / 2];
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot)
                sum += pivot - nums[i];
            else
                sum += nums[i] - pivot;
        }
        return sum;
    }

private:
    //partition 3way
    void partition_3way(vector<int>& nums, int l, int r, int k){
        swap(nums[l], nums[l + rand() % (r - l + 1)]);
        int pviot = nums[l];

        int lt = l, gt = r + 1, i = l + 1;
        while(i < gt){
            if(nums[i] < pviot){
                swap(nums[++lt], nums[i++]);
            }
            else if(nums[i] == pviot){
                i++;
            }
            else{
                swap(nums[--gt], nums[i]);
            }
        }
        swap(nums[l], nums[lt]);

        if(k < lt)
            partition_3way(nums, l, lt - 1, k);
        else if(k >= gt)
            partition_3way(nums, gt, r, k);
    }
};