#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while(l <= r){
            int c = l + (r - l) / 2;
            if(matrix[c / n][c % n] == target) return true;
            if(matrix[c / n][c % n] < target) l = c + 1;
            else r = c - 1;
        }
        return false;
    }
};


//lowerbound
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n;
        while(l < r){
            int c = l + (r - l) / 2;
            if(matrix[c / n][c % n] < target) l = c + 1;
            else r = c;
        }
        return l < m * n && matrix[l / n][l % n] == target;
    }
};