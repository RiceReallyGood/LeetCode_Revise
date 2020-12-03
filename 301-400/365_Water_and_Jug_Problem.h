class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z > x + y) return false;
        if(x == 0 && y == 0) return z == 0;
        int g = GCD(x, y);
        return z % g == 0;
    }

private:
    int GCD(int a, int b) { return b == 0 ? a : GCD(b, a % b); }
};