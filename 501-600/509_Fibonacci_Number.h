#include <algorithm>
using namespace std;

class Solution {
public:
    int fib(int N) {
        if (N < 2) return 1;
        int a = 0, b = 1;

        for (int i = 2; i <= N; i++){
            a += b;
            std::swap(a, b);
        }

        return b;
    }
};