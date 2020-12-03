class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        long ret = m, mask = m;
        while(ret){
            mask = ret + (ret & (-ret));
            if(mask > n) break;
            ret &= mask;
        }
        return ret;
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while(m < n){
            n = n & (n - 1);
        }
        return n;
    }
};