#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int ia = a.length() - 1, ib = b.length() - 1;
        string ret;
        int carry = 0;
        while(ia >= 0 || ib >= 0){
            int na = ia < 0 ? 0 : a[ia] - '0';
            int nb = ib < 0 ? 0 : b[ib] - '0';
            ret.push_back((na ^ nb ^ carry) + '0');
            carry = (na + nb + carry) / 2;
            ia--, ib--;
        }
        if(carry) ret.push_back('1');
        reverse(ret.begin(), ret.end());
        return ret;
    }
};