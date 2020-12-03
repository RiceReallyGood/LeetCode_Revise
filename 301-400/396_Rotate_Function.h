#include <vector>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();

        long sum = 0;
        for(int num : A) sum += num;

        long curr = 0;
        for(int i = 0; i < n; i++)
            curr += i * A[i];
        
        long ret = curr;

        for(int shift = 1; shift < A.size(); shift++){
            curr = curr + sum - n * long(A[n - shift]);
            ret = max(ret, curr);
        }

        return ret;
    }
};