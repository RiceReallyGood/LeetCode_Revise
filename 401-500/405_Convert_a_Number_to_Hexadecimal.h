#include <string>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};


        int mask = 0xf;
        string ret;
        for(int i = 28; i >= 0; i -= 4){
            int digit = (num >> i) & mask;
            if(ret.empty() && digit == 0) continue;
            ret.push_back(hex[digit]);
        }
        return ret;
    }
};