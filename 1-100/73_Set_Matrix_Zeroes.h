#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        bool firstrowzero = false;
        for(int j = 0; j < n; j++){
            if(matrix[0][j] == 0)
                firstrowzero = true;
        }
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            } 
        }
        if(matrix[0][0] == 0){
            for(int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }

        if(firstrowzero){
            for(int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }
    }
};