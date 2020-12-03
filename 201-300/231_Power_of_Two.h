class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0) return false;
        return BitOne(n) == 1;
    }

private:
    int BitOne(int n){
        int count = 0;
        while(n){
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};