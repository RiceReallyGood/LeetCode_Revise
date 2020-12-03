#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int hstep = n, vstep = n;
        int row = 0, col = -1;
        int ele = 1;
        while(true){
            if(hstep == 0) break;
            for(int i = 0; i < hstep; i++)
                matrix[row][++col] = ele++;
            vstep--;
            
            if(vstep == 0) break;
            for(int i = 0; i < vstep; i++)
                matrix[++row][col] = ele++;
            hstep--;

            if(hstep == 0) break;
            for(int i = 0; i < hstep; i++)
                matrix[row][--col] = ele++;
            vstep--;

            if(vstep == 0) break;
            for(int i = 0; i < vstep; i++)
                matrix[--row][col] = ele++;
            hstep--;
        }
        return matrix;
    }
};