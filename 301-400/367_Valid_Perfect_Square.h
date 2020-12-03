class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;

        while(l < r){
            int c = l + (r - l) / 2;
            if(c < num / c) l = c + 1;
            else r = c;
        }
        return num / l == l;
    }
};