#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[m - 1][j] == 'O') dfs(board, m - 1, j);
        }
        for(int i = 1; i < m - 1; i++){
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][n - 1] == 'O') dfs(board, i, n - 1);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'B') board[i][j] = 'O';
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int row, int col){
        board[row][col] = 'B';
        if(row > 0 && board[row - 1][col] == 'O')
            dfs(board, row - 1, col);
        if(row + 1 < board.size() && board[row + 1][col] == 'O')
            dfs(board, row + 1, col);
        if(col > 0 && board[row][col - 1] == 'O')
            dfs(board, row, col - 1);
        if(col + 1 < board[0].size() && board[row][col + 1] == 'O')
            dfs(board, row, col + 1);
    }
};