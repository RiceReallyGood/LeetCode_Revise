#include <vector>
#include <stack>
#include <climits>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        vector<int> prefixmin(nums);
        for(int i = 1; i < n; i++){
            prefixmin[i] = std::min(prefixmin[i - 1], prefixmin[i]);
        }

        stack<int> s;
        for(int i = n - 1; i >= 0; i--){
            if(prefixmin[i] == nums[i])
                continue;
            
            while(!s.empty() && s.top() <= prefixmin[i])
                s.pop();
            
            if(s.empty()){
                s.push(nums[i]);
            }
            else{
                if(s.top() < nums[i])
                    return true;
                else if(s.top() > nums[i])
                    s.push(nums[i]);
            }
        }
        return false;
    }
};

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3) return false;
        int third = INT_MIN;
        stack<int> s;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] < third) return true;

            while(!s.empty() && s.top() < nums[i]){
                third = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};