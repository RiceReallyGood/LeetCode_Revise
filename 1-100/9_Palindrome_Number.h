#include <climits>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int temp = x, rev = 0, rightbound = INT_MAX / 10;
        while(temp){
            int digit = temp % 10;
            if(rev > rightbound || (rev == rightbound && digit > 7))
                return false;
            rev = rev * 10 + digit;
            temp /= 10;
        }
        return rev == x;
    }
};