class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        int l = 1, r = x;
        while(l < r){
            int c = l + (r - l) / 2;
            if(x / c == c) return c;
            if(x / c > c)
                l = c + 1;
            else
                r = c;
        }
        return l - 1;
    }
};