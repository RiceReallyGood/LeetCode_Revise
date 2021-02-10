class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n + 1;
        while (l < r) {
            int c = l + (r - l) / 2;
            int sc = SmallerCount(m, n, c);
            if (sc < k)
                l = c + 1;
            else
                r = c;
        }
        return l - 1;
    }

private:
    int SmallerCount(int m, int n, int num) {
        int res = 0;
        int j = n;

        for (int i = 1; i <= m; i++) {
            while (i * j >= num) --j;
            res += j;
        }

        return res;
    }
};