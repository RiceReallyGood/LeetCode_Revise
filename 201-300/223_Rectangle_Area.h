#include <algorithm>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x = overlap(A, C, E, G);
        int y = overlap(B, D, F, H);
        int ret = -x * y;
        ret += (C - A) * (D - B);
        ret += (G - E) * (H - F);
        return ret;
    }

private:
    int overlap(int A, int B, int C, int D){
        if(C >= B) return 0;
        else if(C >= A)
            return min(B, D) - C;
        else{
            if(D <= A) return 0;
            else return min(B, D) - A;
        }
        return 0;
    }
};