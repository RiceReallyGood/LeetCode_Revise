#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int d[128];
        d['I'] = 1, d['V'] = 5, d['X'] = 10, d['L'] = 50;
        d['C'] = 100, d['D'] = 500, d['M'] = 1000;
        s.push_back('I');
        int ret = 0;
        for(int i = 0; i < s.length() - 1; i++){
            if(d[s[i]] < d[s[i + 1]])
                ret -= d[s[i]];
            else
                ret += d[s[i]];
        }
        return ret;
    }
};