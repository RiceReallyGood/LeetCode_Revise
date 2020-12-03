#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3) return 0;
        int h = 0;
        int val = 0;
        for(int i = 0, j = height.size() - 1; i < j;){
            if(height[i] < height[j]){
                h = max(h, height[i]);
                val += h - height[i++];
            }
            else{
                h = max(h, height[j]);
                val += h - height[j--];
            }
        }
        return val;
    }
};