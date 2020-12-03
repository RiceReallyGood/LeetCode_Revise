#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<int> count(10, 0);
        //rows
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                if(count[board[i][j] - '0'] == 0)
                    count[board[i][j] - '0']++;
                else
                    return false;
            }
            for(int index = 0; index < 10; index++)
                count[index] = 0;
        }

        //columns
        for(int j = 0; j < 9; j++){
            for(int i = 0; i < 9; i++){
                if(board[i][j] == '.') continue;
                if(count[board[i][j] - '0'] == 0)
                    count[board[i][j] - '0']++;
                else
                    return false;
            }
            for(int index = 0; index < 10; index++)
                count[index] = 0;
        }

        //sub-boxes
        for(int startrow = 0; startrow < 9; startrow += 3){
            for(int startcol = 0; startcol < 9; startcol += 3){
                for(int i = startrow; i < startrow + 3; i++){
                    for(int j = startcol; j < startcol + 3; j++){\
                        if(board[i][j] == '.') continue;
                        if(count[board[i][j] - '0'] == 0)
                            count[board[i][j] - '0']++;
                        else
                            return false;
                    }
                }
                for(int index = 0; index < 10; index++)
                    count[index] = 0;
            }
        }
        return true;
    }
};