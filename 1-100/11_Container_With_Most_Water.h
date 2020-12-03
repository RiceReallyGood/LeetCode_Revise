#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        for(int i = 0, j = height.size() - 1; i < j; ){
            if(height[i] < height[j]){
                ret = max(ret, height[i] * (j - i));
                i++;
            }
            else{
                ret = max(ret, height[j] * (j - i));
                j--;
            }
        }
        return ret;
    }
};