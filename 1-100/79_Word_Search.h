#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dfs(i, j, board, used, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(int row, int col, vector<vector<char>>& board,vector<vector<bool>>& used, string& word, int index){
        if(used[row][col] || word[index] != board[row][col]) return false;
        if(index + 1 == word.length()) return  true;
        used[row][col] = true;
        if(row > 0 && dfs(row - 1, col, board, used, word, index + 1)) return true;
        if(row < board.size() - 1 && dfs(row + 1, col, board,  used, word, index + 1)) return true;
        if(col > 0 && dfs(row, col - 1, board, used, word, index + 1)) return true;
        if(col < board[0].size() - 1 && dfs(row, col + 1, board, used, word, index + 1)) return true;
        used[row][col] = false;
        return false;
    }
};