#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> nextgreater;
        for(int i = int(nums2.size()) - 1; i >= 0; i--){
            while(!s.empty() && nums2[i] >= s.top())
                s.pop();
            if(!s.empty()) nextgreater[nums2[i]] = s.top();
            s.push(nums2[i]);
        }

        int n = nums1.size();
        vector<int> ret(n);
        for(int i = 0; i < n; i++){
            if(nextgreater.find(nums1[i]) != nextgreater.end())
                ret[i] = nextgreater[nums1[i]];
            else
                ret[i] = -1;
        }
        return ret;
    }
};