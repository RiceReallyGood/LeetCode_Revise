class Solution {
public:
    int lastRemaining(int n) {
        int start = 1, diff = 1, count = n;

        while(count > 1){
            start += diff;
            diff *= 2;
            count /= 2;

            if(count == 1) break;

            if(count & 1) start += diff;
            diff *= 2;
            count /= 2;
        }
        return start;
    }
};

class Solution {
public:
    int lastRemaining(int n) {
        if (n == 1) return 1;
        return 2 * (n / 2 + 1 - lastRemaining(n / 2));
    }
};