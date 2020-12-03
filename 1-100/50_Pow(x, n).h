class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) x = 1. / x;
        double ret = 1.;
        while(n){
            if(n & 1)
                ret *= x;
            x *= x;
            n /= 2;
        }
        return ret;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        if(n >= 0) return QuickPow(x, n);
        else return QuickPow(1. / x, -long(n));
    }

private:
    double QuickPow(double x, long n){
        if(n == 0) return 1.;
        if(n & 1) return x * QuickPow(x * x, n / 2);
        else return QuickPow(x * x, n / 2);
    }
};