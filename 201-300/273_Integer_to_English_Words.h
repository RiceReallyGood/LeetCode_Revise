#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    Solution(){
        digits = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        dozens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        thousands ={"", " Thousand", " Million", " Billion"};
    }
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        vector<int> parts;
        while(num){
            parts.push_back(num % 1000);
            num /= 1000;
        }

        string ret;
        for(int i = parts.size() - 1; i >= 0; i--){
            if(parts[i] == 0) continue;
            if(!ret.empty()) ret.push_back(' ');
            ret += ToWord(parts[i]);
            ret += thousands[i];
        }
        return ret;
    }

private:
    vector<string> digits;
    vector<string> dozens;
    vector<string> teens;
    vector<string> thousands;
    string ToWord(int num){
        string ret;
        if(num >= 100){
            ret += digits[num / 100] + "Hundred";
            ret.push_back(' ');
            num %= 100;
        }

        if(num >= 20){
            ret += dozens[num / 10];
            ret.push_back(' ');
            num %= 10;
        }

        if(num >= 10){
            ret += teens[num - 10];
            ret.push_back(' ');
            num = 0;
        }

        if(num > 0){
            ret += digits[num];
            ret.push_back(' ');
        }

        ret.pop_back();
        return ret;
    }
};