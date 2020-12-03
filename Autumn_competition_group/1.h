#include <vector>
using namespace std;
class Solution {
public:
    int paintingPlan(int n, int k) {
        if(k == n * n || k == 0) return 1;
        static vector<int> fact = {1, 1, 2, 6, 24, 120, 720};
        vector<int> bio(n + 1);
        for(int i = 0; i <= n; i++)
            bio[i] = fact[n] / fact[i] / fact[n - i];

        int count = 0;
        for(int p = 0; p < n; p++){
            if(k - p * n < 0) break;
            if((k - p * n) % (n - p) == 0){
                int q = (k - p * n) / (n - p);
                count += bio[p] * bio[q];
            }
        }
        return count;
    }
};