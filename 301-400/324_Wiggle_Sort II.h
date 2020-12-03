#include <vector>
#include <random>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        this->n = nums.size();
        srand(time(NULL));
        partition_3way(nums, 0, n - 1, n / 2);
    }

private:
    int n;
    int index(int i){ return (2 * i + 1) % (n | 1); }

    void partition_3way(vector<int>& nums, int l, int r, int k){
        swap(nums[index(l)], nums[index(rand() % (r - l + 1) + l)]);
        int v = nums[index(l)];
        int gt = l, lt = r + 1;
        int i = l + 1;
        while(i < lt){
            if(nums[index(i)] < v){
                swap(nums[index(lt - 1)], nums[index(i)]);
                lt--;
            }
            else if(nums[index(i)] > v){
                swap(nums[index(i)], nums[index(gt + 1)]);
                gt++;
                i++;
            }
            else
                i++;
        }

        swap(nums[index(l)], nums[index(gt)]);
        if(k >= gt && k < lt)
            return;
        if(lt <= k)
            partition_3way(nums, lt, r, k);
        else
            partition_3way(nums, l, gt - 1, k);
    }
};