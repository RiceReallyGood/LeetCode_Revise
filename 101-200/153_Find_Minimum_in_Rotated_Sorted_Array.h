#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while(l < r){
            if(nums[l] < nums[r]) return nums[l];
            int c = l + (r - l) / 2;
            if(nums[c] >= nums[l])
                l = c + 1;
            else
                r = c;
        }
        return nums[l];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        if(nums[l] < nums[r]) return nums[l];

        while(l < r){
            int c = l + (r - l) / 2;
            if(nums[c] >= nums[0])
                l = c + 1;
            else
                r = c;
        }
        return nums[l];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while(l < r){
            int c = l + (r - l) / 2;
            if(nums[c] < nums[r])
                r = c;
            else
                l = c + 1;
        }
        return nums[l];
    }
};