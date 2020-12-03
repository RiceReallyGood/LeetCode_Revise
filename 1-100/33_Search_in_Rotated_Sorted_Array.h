#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;

        //find index of minimal value
        int l = 0, r = nums.size();
        while(l < r){
            int c = l + (r - l) / 2;
            if(nums[c] > nums[0])
                l = c + 1;
            else
                r = c;
        }
        int anchor = l;

        if(target >= nums[0])
            l = 0, r = anchor;
        else
            l = anchor, r = nums.size();
        
        while(l < r){
            int c = l + (r - l) / 2;
            if(nums[c] == target) return c;

            if(nums[c] > target)
                r = c;
            else
                l = c + 1;
        }

        if(l < nums.size() && nums[l] == target)
            return l;
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        if(sz == 0) return -1;
        if(sz == 1) return nums[0] == target ? 0 : -1;

        //find index of maximal value
        int l = 0, r = sz - 1;
        while(l < r){
            int c = l + (r - l) / 2;
            if(nums[c] > nums[c + 1])
                l = r = c;
            else{
                if(nums[c] < nums[l])
                    r = c - 1;
                else
                    l = c + 1;
            }
        }
        int anchor = l;
        if(target >= nums[0])
            l = 0, r = anchor;
        else
            l = anchor + 1, r = sz - 1;
        
        while(l <= r){
            int c = l + (r - l) / 2;
            if(nums[c] == target)
                return c;
            else if(nums[c] > target)
                r = c - 1;
            else
                l = c + 1;
        }
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        if(sz == 0) return -1;
        if(sz == 1) return nums[0] == target ? 0 : -1;

        int l = 0, r = sz - 1;
        while(l <= r){
            int c = l + (r - l) / 2;
            if(nums[c] == target)
                return c;
            
            if(nums[c] >= nums[l]){
                if(target >= nums[l] && target < nums[c])
                    r = c - 1;
                else
                    l = c + 1;
            }
            else{
                if(target > nums[c] && target <= nums[r])
                    l = c + 1;
                else
                    r = c - 1;
            }
        }
        return -1;
    }
};