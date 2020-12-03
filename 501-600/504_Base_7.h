#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        bool negative = num < 0;
        num = negative ? -num : num;

        string res;
        while(num){
            res.push_back('0' + num % 7);
            num /= 7;
        }
        if(negative) res.push_back('-');
        reverse(res.begin(), res.end());
        return res;
    }
};