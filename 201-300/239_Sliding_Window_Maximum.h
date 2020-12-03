#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        vector<int> ret;
        for(int i = 0; i < k; i++){
            while(!window.empty() && window.back() < nums[i])
                window.pop_back();
            window.push_back(nums[i]);
        }
        ret.push_back(window.front());

        for(int i = k; i < nums.size(); i++){
            while(!window.empty() && window.back() < nums[i])
                window.pop_back();
            window.push_back(nums[i]);

            if(nums[i - k] == window.front())
                window.pop_front();
            
            ret.push_back(window.front());
        }

        return ret;
    }
};