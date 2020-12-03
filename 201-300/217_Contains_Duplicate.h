#include <vector>
#include <random>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numset;
        for(int num : nums){
            if(numset.find(num) != numset.end())
                return true;
            numset.insert(num);
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty()) return false;
        srand(time(NULL));
        return recurse(nums, 0, nums.size() - 1);
    }

private:
    bool recurse(vector<int>& nums, int l, int r){
        if(l >= r) return false;
        swap(nums[l], nums[rand() % (r - l + 1) + l]);
        int lt = l, gt = r + 1;
        int i = l + 1;
        while(i < gt){
            if(nums[i] < nums[l])
                swap(nums[i++], nums[++lt]);
            else if(nums[i] > nums[l])
                swap(nums[i], nums[--gt]);
            else
                return true;
        }

        swap(nums[l], nums[lt]);
        if(recurse(nums, l, lt - 1)) return true;
        if(recurse(nums, gt, r)) return true;
        return false;
    }
};