class Solution {
public:
    int integerReplacement(int n) {
        int count = 0;
        while(n != 1 && n != 3){
            if(n % 2 == 0) n /= 2;
            else{
                if((n & 2) == 2){
                    n = n / 2 + 1;
                }
                else{
                    n = n / 2;
                }
                count += 2;
            }
        }
        return n == 3 ? count + 2 : count;
    }
};