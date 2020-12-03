#include <vector>
using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        a %= M;
        if(a == 1) return 1;

        int pow10 = a, ret = 1;
        for(int i = b.size() - 1; i >= 0; i--){
            ret = (ret * pow(pow10, b[i])) % M;
            pow10 = pow(pow10, 10);
        }
        return ret;
    }

private:
    static const int M = 1337;
    int pow(int n, int k){
        if(k == 0) return 1;
        if(k & 1) return (n * pow((n * n) % M, k / 2)) % M;
        else return pow((n * n) % M, k / 2);
    }
};