#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret(1, 0);
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < ret.size(); j++)
                ret[j] = ret[j] << 1;
            for(int j = ret.size(); j >= 0; j--)
                ret.push_back(ret[j] + 1);
        }
        return ret;
    }
};