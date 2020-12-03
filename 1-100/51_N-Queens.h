#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n <= 0) return {};
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        vector<bool> col(n, false);
        vector<bool> lu(2 * n - 1, false), ru(2 * n - 1, false);
        recurse(board, 0, n, res, col, lu, ru);
        return res;
    }

private:
    void recurse(vector<string>& board, int line, int n, vector<vector<string>>& res,
            vector<bool>& col, vector<bool>& lu, vector<bool>& ru){
        if(line == n){
            res.emplace_back(board);
            return;
        }
        for(int j = 0; j < n; j++){
            if(col[j] || lu[line - j + (n - 1)] || ru[line + j])
                continue;
            board[line][j] = 'Q';
            col[j] = lu[line - j + (n - 1)] = ru[line + j] = true;
            recurse(board, line + 1, n, res, col, lu, ru);
            col[j] = lu[line - j + (n - 1)] = ru[line + j] = false;
            board[line][j] = '.';
        }
    }
};

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n <= 0) return {};
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        cols.resize(n);
        recurse(board, 0, n, res);
        return res;
    }

private:
    vector<int> cols;
    void recurse(vector<string>& board, int line, int n, vector<vector<string>>& res){
        if(line == n){
            res.emplace_back(board);
            return;
        }
        for(int j = 0; j < n; j++){
            if(IsValid(line, j)){
                cols[line] = j;
                board[line][j] = 'Q';
                recurse(board, line + 1, n, res);
                board[line][j] = '.';
            }
        }
    }

    bool IsValid(int row, int col){
        for(int i = 0; i < row; i++){
            if(col == cols[i]) return false;
            if(row + col == i + cols[i]) return false;
            if(row - col == i - cols[i]) return false;
        }
        return true;
    }
};