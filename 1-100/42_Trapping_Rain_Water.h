#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int h = 0, vol = 0;
        int i = 0, j = int(height.size()) - 1;
        while(i < j){
            if(height[i] <= height[j]){
                h = max(h, height[i]);
                vol += h - height[i];
                i++;
            }
            else{
                h = max(h, height[j]);
                vol += h - height[j];
                j--;
            }
        }
        return vol;
    }
};