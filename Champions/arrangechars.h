#include <string>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string ret;

        for(int i = 0; i < s.length(); i++){
            if(!ret.empty() && ret.back() == (s[i] ^ 32))
                ret.pop_back();
            else
                ret.push_back(s[i]);
        }

        return ret;
    }
};