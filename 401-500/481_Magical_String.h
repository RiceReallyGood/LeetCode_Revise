#include <algorithm>

class Solution {
public:
    int magicalString(int n) {
        if(n == 0) return 0;
        int digits[100000];
        digits[0] = 1;
        digits[1] = 2;
        digits[2] = 2;
        int sum = 1;

        int i = 2, j = 3, d = 1;
        while(j < n){
            sum += d;
            digits[j++] = 2 - d;
            if(--digits[i] == 0){
                i++;
                d = 1 - d;
            }
        }

        return sum;
    }
};