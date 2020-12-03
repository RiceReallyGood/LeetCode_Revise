#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int ret = 0;
        vector<int> heights(n, 0);
        for(int i= 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            ret = max(ret, largestRectangleArea(heights));
        }
        return ret;
    }

private:
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