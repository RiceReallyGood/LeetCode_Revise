class Solution {
public:
    int trailingZeroes(int n) {
        int pow5 = 0;
        while(n){
            n /= 5;
            pow5 += n;
        }
        return pow5;
    }
};