#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.length();
        if(len == k) return "0";
        string ret;

        for(int i = 0; i < len; i++){
            while(k > 0 && !ret.empty() && num[i] < ret.back()){
                k--;
                ret.pop_back();
            }
            if(ret.empty() && num[i] == '0') continue;
            ret.push_back(num[i]);
        }

        while(k > 0 && !ret.empty()){
            k--;
            ret.pop_back();
        }

        if(ret.empty()) ret.push_back('0');
        return ret;
    }
};