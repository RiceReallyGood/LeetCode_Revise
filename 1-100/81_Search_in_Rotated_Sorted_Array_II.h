#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        if(nums[0] == target) return true;

        int l = 0, r = nums.size() - 1;
        while(l <= r && nums[l] == nums[r])
            l++;

        while(l <= r){
            int c = l + (r - l) / 2;
            if(nums[c] == target) return true;
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
        return false;
    }
};

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        if(nums[0] == target) return true;
        int leftbound = 0, rightbound = nums.size() - 1;
        while(nums[leftbound] == nums[rightbound]){
            leftbound++;
            rightbound--;
        }
        if(leftbound > rightbound) return false;

        int l = leftbound, r = rightbound;

        //find index of the maximal value
        while(l < r){
            int c = l + (r - l) / 2;
            if(nums[c] > nums[c + 1])
                l = r = c;
            else{
                if(nums[c] >= nums[l])
                    l = c + 1;
                else
                    r = c - 1;
            }
        }
        int anchor = l;
        if(target >= nums[leftbound] && target <= nums[anchor])
            l = leftbound, r = anchor;
        else
            l = anchor + 1, r = rightbound;
        
        while(l <= r){
            int c = l + (r - l) / 2;
            if(nums[c] == target)
                return true;
            
            if(nums[c] < target)
                l = c + 1;
            else
                r = c - 1;
        }
        return false;
    }
};