#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() < 2) return 0;
        int maxval = 0;
        for(int i = 0, j = height.size() - 1; i < j;){
            if(height[i] < height[j]){
                maxval = max(maxval, height[i] * (j - i));
                i++;
            }
            else{
                maxval = max(maxval, height[j] * (j - i));
                j--;
            }
        }
        return maxval;
    }
};