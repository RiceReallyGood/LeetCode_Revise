#include <string>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        bool isJewel[128] = {};
        for(char c : J) isJewel[c] = true;

        int res = 0;
        for(char c: S){
            if(isJewel[c])
                res++;
        }
        return res;
    }
};