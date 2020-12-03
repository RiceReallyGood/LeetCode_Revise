#include <vector>
using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        if(nums.size() < 2) return false;
        int n = nums.size();

        for(int i = 0; i < n; i++)
            nums[i] %= n;
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) continue;

            int fast = i, slow = i;
            bool signi= nums[i] > 0;

            do{
                fast = (fast + nums[fast] + n) % n;
                if(nums[fast] == 0 || (nums[fast] > 0) != signi)
                    break;
                fast = (fast + nums[fast] + n) % n;
                if(nums[fast] == 0 || (nums[fast] > 0) != signi)
                    break;
                slow = (slow + nums[slow] + n) % n;
            }while(fast != slow);
            if(fast == slow) return true;

            fast = i;

            do{
                nums[fast] = 0;
            }while(nums[fast] != 0 && (nums[fast] > 0) == signi);
        }
        return false;
    }
};