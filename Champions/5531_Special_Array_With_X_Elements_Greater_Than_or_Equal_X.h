#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n;
        while(l <= r){
            int c = l + (r - l) / 2;
            int count = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] >= c)
                    count++;
            }

            if(count == c) return c;

            if(count < c)
                r = c - 1;
            else
                l = c + 1;
        }
        return -1;
    }
};