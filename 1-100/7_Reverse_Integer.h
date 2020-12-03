#include <climits>

class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        long num = x;
        if(num < 0){
            negative = true;
            num = -num;
        }
        long rev = 0;
        while(num){
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        if(negative) rev = -rev;
        if(rev < INT_MIN || rev > INT_MAX)
            return 0;
        return rev;
    }
};

class Solution {
public:
    int reverse(int x) {
        int ret = 0, pop;
        int rightbound = INT_MAX / 10;
        int leftbound = INT_MIN / 10;
        while(x != 0){
            pop = x % 10;
            if (ret > rightbound || (ret == rightbound && pop > 7)) return 0;
            if (ret < leftbound || (ret == leftbound  && pop < -8)) return 0;
            ret = ret * 10 + pop;
            x /= 10;
        }
        return ret;
    }
};