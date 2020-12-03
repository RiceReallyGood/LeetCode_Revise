#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        int vlen = matrix.size(), hlen = matrix[0].size();
        vector<int> ret(vlen * hlen);
        int row = 0, col = -1;
        int count = 0;
        while(true){
            if(hlen == 0) break;
            for(int i = 0; i < hlen; i++){
                ret[count++] = matrix[row][++col];
            }
            vlen--;

            if(vlen == 0) break;
            for(int i = 0; i < vlen; i++){
                ret[count++] = matrix[++row][col];
            }
            hlen--;

            if(hlen == 0) break;
            for(int i = 0; i < hlen; i++){
                ret[count++] = matrix[row][--col];
            }
            vlen--;

            if(vlen == 0) break;
            for(int i = 0; i < vlen; i++){
                ret[count++] = matrix[--row][col];
            }
            hlen--;
        }
        return ret;
    }
};