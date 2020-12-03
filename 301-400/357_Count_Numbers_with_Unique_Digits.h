class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;
        int totalcount = 10;
        int lengthKcount = 9;
        for(int len = 2; len <= n && len <= 10; len++){
            lengthKcount *= (11 - len);
            totalcount += lengthKcount;
        }
        return totalcount;
    }
};