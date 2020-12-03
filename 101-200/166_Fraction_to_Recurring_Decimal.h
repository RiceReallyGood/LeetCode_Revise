#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long a = numerator, b = denominator;
        string ret;
        if((a > 0 && b < 0) || (a < 0 && b > 0))
            ret.push_back('-');
        a = abs(a), b = abs(b);
        ret += to_string(a / b);
        a %= b;
        if(a == 0) return ret;
        ret.push_back('.');
        unordered_map<int,int> index;
        while(a && index.find(a) == index.end()){
            index[a] = ret.length();
            a *= 10;
            ret.push_back(a / b + '0');
            a %= b;
        }
        if(a == 0) return ret;
        ret.insert(index[a], "(");
        ret.push_back(')');
        return ret;
    }
};