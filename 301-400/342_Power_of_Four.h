class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0) return false;
        while(num & 3 == 0)
            num >>= 2;
        return num == 1;
    }
};

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num < 0 || (num & (num - 1))) return false;
        return num & 0x55555555;
    }
};