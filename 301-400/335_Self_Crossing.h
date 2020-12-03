#include <vector>
using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if(x.size() >= 4 && x[3] >= x[1] && x[2] <= x[0])
            return true;
        
        if(x.size() >= 5){
            if(x[4] >= x[2] && x[3] <= x[1])
                return true;
            if(x[4] + x[0] >= x[2] && x[1] == x[3])
                return true;
        }

        for(int i = 5; i < x.size(); i++){
            if(x[i - 1] <= x[i - 3]){
                if(x[i] >= x[i - 2])
                    return true;
                if(x[i - 4] <= x[i - 2] && x[i - 1] + x[i - 5] >= x[i - 3] && x[i] + x[i - 4] >= x[i - 2])
                    return true;
            }
        }

        return false;
    }
};