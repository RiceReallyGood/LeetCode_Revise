#include <vector>
#include <climits>
#include <cmath>
using namespace std;


//TLE
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        int divisorsign = divisor < 0 ? -1 : 1;
        divisor = abs(divisor);
        int ret = 0;
        if(dividend < 0){
            while(dividend <= -divisor){
                ret--;
                dividend += divisor;
            }
        }
        else{
            while(dividend >= divisor){
                ret++;
                dividend -= divisor;
            }
        }

        return divisorsign == -1 ? -ret : ret;
    }
};

class Solution {
public:
    int divide(int dividend, int divisor){
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        long a = dividend, b = divisor;
        bool negative = false;
        if((a < 0 && b > 0) || (a > 0 && b < 0))
            negative = true;
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        vector<long> seq;
        while(a >= b){
            seq.push_back(b);
            b += b;
        }
        int sz = seq.size();
        long ret = 0;
        for(int i = sz - 1; i >= 0; i--){
            if(seq[i] <= a){
                ret += (1 << i);
                a -= seq[i];
            }
        }
        return negative ? -ret : ret;
    }
};