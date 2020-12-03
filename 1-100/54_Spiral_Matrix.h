#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        int row = 0, col = -1;
        int hstep = matrix[0].size(), vstep = matrix.size();
        vector<int> ret(hstep * vstep);
        int index = 0;
        while(true){
            if(hstep <= 0) break;
            for(int i = 0; i < hstep; i++)
                ret[index++] = matrix[row][++col];
            vstep--;

            if(vstep <= 0) break;
            for(int i = 0; i < vstep; i++)
                ret[index++] = matrix[++row][col];
            hstep--;

            if(hstep <= 0) break;
            for(int i = 0; i < hstep; i++)
                ret[index++] = matrix[row][--col];
            vstep--;

            if(vstep <= 0) break;
            for(int i = 0; i < vstep; i++)
                ret[index++] = matrix[--row][col];
            hstep--;
        }
        return ret;
    }
};