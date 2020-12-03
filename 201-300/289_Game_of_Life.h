#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int count = 0;
                if(i > 0){
                    if(j > 0) count += board[i - 1][j - 1] > 0 ? 1 : 0;
                    count += board[i - 1][j] > 0 ? 1 : 0;
                    if(j < n - 1) count += board[i - 1][j + 1] > 0 ? 1 : 0;
                }
                if(j > 0) count += board[i][j - 1] > 0 ? 1 : 0;
                if(j < n - 1) count += board[i][j + 1] > 0 ? 1 : 0;
                if(i < m - 1){
                    if(j > 0) count += board[i + 1][j - 1] > 0 ? 1 : 0;
                    count += board[i + 1][j] > 0 ? 1 : 0;
                    if(j < n - 1) count += board[i + 1][j + 1] > 0 ? 1 : 0;
                }

                count = count == 0 ? 9 : count;
                board[i][j] = board[i][j] == 0 ? -count : count;
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 2 || board[i][j] == 3 || board[i][j] == -3)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
    }
};