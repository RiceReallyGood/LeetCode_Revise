#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> S;
        S.push(-1);
        int ret = 0;
        for(int i = 0; i < heights.size(); i++){
            while(S.top() != -1 && heights[S.top()] >= heights[i]){
                int h = heights[S.top()];
                S.pop();
                int width = i - S.top() - 1;
                ret = max(ret, h * width);
            }
            S.push(i);
        }
        while(S.top() != -1){
            int h = heights[S.top()];
            S.pop();
            int width = heights.size() - S.top() - 1;
            ret = max(ret, h * width);
        }
        return ret;
    }
};