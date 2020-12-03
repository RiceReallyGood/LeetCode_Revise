class Solution {
public:
    int getSum(int a, int b) {
        int bitmask = 0, carry = 0;;

        int ret = 0;
        for(int i = 0; i < 32; i++){
            bitmask = 1 << i;
            carry <<= 1;
            int bita = a & bitmask;
            int bitb = b & bitmask;

            ret |= (bita ^ bitb ^ carry);
            carry = (bita & bitb) | (carry & (bita | bitb));
        }
        return ret;
    }
};