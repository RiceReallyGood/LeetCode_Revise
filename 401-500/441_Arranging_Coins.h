class Solution {
public:
    int arrangeCoins(int n) {
        if(n < 2) return n;
        long long l = 0, r = n;
        while(l < r){
            long long c = l + (r - l) / 2;
            if(c * (c + 1) / 2 <= n)
                l = c + 1;
            else
                r = c;
        }
        return l - 1;
    }
};