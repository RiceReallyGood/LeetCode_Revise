#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        if(n <= 0) return 0;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false);
        vector<bool> lu(2 * n - 1, false), ru(2 * n - 1, false);
        return recurse(board, 0, n, col, lu, ru);
    }

private:
    int recurse(vector<string>& board, int line, int n,
            vector<bool>& col, vector<bool>& lu, vector<bool>& ru){
        if(line == n) return 1;
        int count = 0;
        for(int j = 0; j < n; j++){
            if(col[j] || lu[line - j + (n - 1)] || ru[line + j])
                continue;
            board[line][j] = 'Q';
            col[j] = lu[line - j + (n - 1)] = ru[line + j] = true;
            count += recurse(board, line + 1, n, col, lu, ru);
            col[j] = lu[line - j + (n - 1)] = ru[line + j] = false;
            board[line][j] = '.';
        }
        return count;
    }
};

class Solution {
public:
    int totalNQueens(int n) {
        if(n <= 0) return 0;
        vector<int> cols(n);
        return recurse(cols, 0);
    }

private:
    int recurse(vector<int>& cols, int row){
        if(row == cols.size()) return 1;
        int count = 0;
        for(int j = 0; j < cols.size(); j++){
            if(IsValid(cols, row, j)){
                cols[row] = j;
                count += recurse(cols, row + 1);
            }
        }
        return count;
    }

    bool IsValid(vector<int>& cols, int row, int col){
        for(int i = 0; i < row; i++){
            if(col == cols[i]) return false;
            if(row + col == i + cols[i]) return false;
            if(row - col == i - cols[i]) return false;
        }
        return true;
    }
};

class Solution {
public:
    int totalNQueens(int n) {
        int all = (1 << n) - 1;
        return recurse(all, 0, 0, 0);
    }

private:
    int recurse(int all, int cols, int hills, int dales){
        if(cols == all) return 1;

        int free_cols = all & ~(cols | hills | dales);
        int count = 0;
        while(free_cols){
            int curr_col = (-free_cols) & free_cols;
            count += recurse(all, (cols | curr_col), 
                    ((hills | curr_col) << 1) & all,
                    ((dales | curr_col) >> 1));
            free_cols ^= curr_col;
        }
        return count;
    }
};