#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        for(int W = sqrt(area); W >= 1; W--){
            if(area % W == 0)
                return {area / W, W};
        }
        return {0, 0};
    }
};