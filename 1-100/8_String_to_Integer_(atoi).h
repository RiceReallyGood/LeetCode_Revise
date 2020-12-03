#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int index = 0, len = str.length();
        while(index < len && str[index] == ' ') index++;
        if(index == len) return 0;

        int ret = 0;
        if(str[index] == '-'){
            index++;
            while(index < len && str[index] >= '0' && str[index] <= '9'){
                int digit = str[index] - '0';
                if(ret < INT_MIN / 10 || (ret == INT_MIN / 10 && digit > 8))
                    return INT_MIN;
                ret = ret * 10 - digit;
                index++;
            }
        }
        else{
            if(str[index] == '+') index++;
            while(index < len && str[index] >= '0' && str[index] <= '9'){
                int digit = str[index] - '0';
                if(ret > INT_MAX / 10 || (ret == INT_MAX / 10 && digit > 7))
                    return INT_MAX;
                ret = ret * 10 + digit;
                index++;
            }
        }
        return ret;
    }
};