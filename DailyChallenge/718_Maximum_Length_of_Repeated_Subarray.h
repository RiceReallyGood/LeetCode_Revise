#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        int ret = 0;

        for(int shift = n - 1; shift >= 0; shift--){
            int i = 0, j = shift;
            int prevlen = 0;
            while(i < m && j < n){
                if(A[i++] == B[j++]) prevlen++;
                else prevlen = 0;
                ret = max(ret, prevlen);
            }
        }

        for(int shift = 1; shift < m; shift++){
            int i = shift, j = 0;
            int prevlen = 0;
            while(i < m && j < n){
                if(A[i++] == B[j++]) prevlen++;
                else prevlen = 0;
                ret = max(ret, prevlen);
            }
        }

        return ret;
    }
};