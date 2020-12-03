#include <vector>
#include <queue>
#include <random>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.begin() + k);

        for(int i = k ; i < nums.size(); i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        partition(nums, nums.size() - k + 1, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }

private:
    void partition(vector<int>& nums, int k, int l, int r){
        swap(nums[l], nums[rand() % (r - l + 1) + l]);
        int i = l + 1, j = r;
        while(true){
            while(i <= r && nums[i] < nums[l]) i++;
            while(j > l && nums[j] > nums[l]) j--;
            if(j <= i) break;
            swap(nums[i], nums[j]);
            i++, j--;
        }

        swap(nums[l], nums[j]);
        if(j == k - 1)
            return;
        if(j < k - 1)
            partition(nums, k, j + 1, r);
        else
            partition(nums, k, l, j - 1);
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        partition(nums, nums.size() - k + 1, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }

private:
    void partition(vector<int>& nums, int k, int l, int r){
        swap(nums[l], nums[rand() % (r - l + 1) + l]);
        int lt = l, gt = r + 1;
        int i = l + 1;
        while(i < gt){
            if(nums[i] < nums[l]){
                swap(nums[lt + 1], nums[i]);
                i++;
                lt++;
            }
            else if(nums[i] > nums[l]){
                swap(nums[i], nums[gt - 1]);
                gt--;
            }
            else
                i++;
        }

        swap(nums[l], nums[lt]);
        if(k - 1 >= lt && k - 1 < gt)
            return;
        if(gt <= k - 1)
            partition(nums, k, gt, r);
        else
            partition(nums, k, l, lt - 1);
    }
};