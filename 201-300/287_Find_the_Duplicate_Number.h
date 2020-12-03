#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int l = 1, r = n;

        while(l < r){
            int c = l + (r - l) / 2;
            int le = 0;
            for(int i = 0; i <= n; i++){
                if(nums[i] <= c)
                    le++;
            }

            if(le <= c)
                l = c + 1;
            else
                r = c;
        }
        return l;
    }
};