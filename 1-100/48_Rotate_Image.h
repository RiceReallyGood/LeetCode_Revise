#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int layer = 0; layer < n / 2; layer++){
            for(int i = layer; i < n - 1 - layer; i++){
                int temp = matrix[layer][i];
                matrix[layer][i] = matrix[n - 1 - i][layer];
                matrix[n - 1 - i][layer] = matrix[n - 1 - layer][n - 1 - i];
                matrix[n - 1 - layer][n - 1 - i] = matrix[i][n - 1 - layer];
                matrix[i][n - 1 - layer] = temp;
            }
        }
    }
};


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0, j = n - 1; i < j; i++, j--)
            swap(matrix[i], matrix[j]);
        
        for(int i = 0; i < n - 1; i++)
            for(int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};