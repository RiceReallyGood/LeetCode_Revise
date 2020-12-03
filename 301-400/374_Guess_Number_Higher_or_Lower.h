int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;

        while(l < r){
            int c = l + (r - l) / 2;
            int g = guess(c);
            if(g == 0) return c;
            if(g > 0) l = c + 1;
            else r = c - 1;
        }
        return l;
    }
};