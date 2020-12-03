class Solution {
public:
    int findNthDigit(int n) {
        int len = 1, count = 9;
        while(long(n) > long(len) * long(count)){
            n -= len * count;
            count *= 10;
            len++;
        }
        int num = pow(10, len - 1) + (n - 1) / len;
        n = (n - 1) % len;
        for(int i = 0; i < len - n - 1; i++) num /= 10;
        return num % 10;
    }

private:
    int pow(int n, int k){
        if(k == 0) return 1;
        if(k == 1) return n;

        if(k & 1) return n * pow(n * n, k / 2);
        else return pow(n * n, k / 2);
    }
};