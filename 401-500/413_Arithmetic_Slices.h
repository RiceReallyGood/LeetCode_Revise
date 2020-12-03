#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3) return 0;
        int n = A.size(), ret = 0;

        int diff = A[1] - A[0], len = 2;

        for(int i = 2; i < n; i++){
            if(A[i] - A[i - 1] != diff){
                ret += (len - 1) * (len - 2) / 2;
                len = 2;
                diff = A[i] - A[i - 1];
            }
            else
                len++;
        }
        ret += (len - 1) * (len - 2) / 2;
        return ret;
    }
};