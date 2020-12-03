#include <vector>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        if(A.size() < 2) return 0;
        int prevmax = A[0] + 0;
        int ret = 0;
        for(int i = 1; i < A.size(); i++){
            ret = max(ret, prevmax + A[i] - i);
            prevmax = max(prevmax, A[i] + i);
        }
        return ret;
    }
};