class Solution {
public:
    int countDigitOne(int n) {
        if(n < 0) return 0;
        int pow10 = 0;
        int count = 0;
        int remainder = 0;
        while(n){
            pow10 = pow10 == 0 ? 1 : pow10 * 10;
            if(n % 10 == 0){
                count += n / 10 * pow10;
            }
            else if(n % 10 == 1){
                count += n / 10 * pow10 + remainder + 1;
            }
            else{
                count += (n / 10 + 1) * pow10;
            }
            remainder = n % 10 * pow10 + remainder;
            pow10 *= 10;
            n /= 10;
        }
        return count;
    }
};