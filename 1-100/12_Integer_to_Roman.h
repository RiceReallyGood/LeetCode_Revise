#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ret;
        int thousand = num / 1000;
        num %= 1000;
        ret += string(thousand, 'M');
        int hundred = num / 100;
        num %= 100;
        if(hundred == 9)
            ret += "CM";
        else if(hundred == 4)
            ret += "CD";
        else{
            if(hundred >= 5)
                ret += "D";
            ret += string(hundred % 5, 'C');
        }
        int tens = num / 10;
        num %= 10;
        if(tens == 9)
            ret += "XC";
        else if(tens == 4)
            ret += "XL";
        else{
            if(tens >= 5)
                ret += "L";
            ret += string(tens % 5, 'X');
        }
        if(num == 9)
            ret += "IX";
        else if(num == 4)
            ret += "IV";
        else{
            if(num >= 5)
                ret += "V";
            ret += string(num % 5, 'I');
        }
        return ret;
    }
};