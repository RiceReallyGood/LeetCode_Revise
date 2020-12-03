#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.empty()) return num2;
        if(num2.empty()) return num1;

        string ret;
        int i = num1.length() - 1, j = num2.length() - 1;
        int carry = 0;
        while(i >= 0 || j >= 0){
            int d1 = i >= 0 ? num1[i] - '0' : 0;
            int d2 = j >= 0 ? num2[j] - '0' : 0;
            ret.push_back((d1 + d2 + carry) % 10 + '0');
            carry = (d1 + d2 + carry) / 10;
            i--, j--;
        }
        if(carry != 0) ret.push_back(carry + '0');
        reverse(ret.begin(), ret.end());

        return ret;
    }
};