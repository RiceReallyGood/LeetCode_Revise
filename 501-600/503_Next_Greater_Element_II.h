#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) return {};
        int N = nums.size();
        int maxele = nums[0], maxindex = 0;
        for (int i = 1; i < N; i++) {
            if (nums[i] > maxele) {
                maxele = nums[i];
                maxindex = i;
            }
        }

        stack<int> s;
        vector<int> res(N, -1);
        s.push(maxele);

        for (int i = maxindex == 0 ? N - 1 : maxindex - 1; i != maxindex; i = i == 0 ? N - 1 : i - 1) {
            while (!s.empty() && nums[i] >= s.top())
                s.pop();

            if (!s.empty()) res[i] = s.top();
            s.push(nums[i]);
        }

        return res;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) return {};
        int N = nums.size();
        stack<int> s;
        vector<int> res(N, -1);

        for(int i = 0; i < N; i++){
            while(!s.empty() && nums[s.top()] < nums[i]){
                res[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }

        for(int i = 0; i < N; i++){
            while(nums[s.top()] < nums[i]){
                res[s.top()] = nums[i];
                s.pop();
            }
        }

        return res;
    }
};