#include <vector>
#include <unordered_set>
using namespace std;

//recursive solver
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rowcontain(9, unordered_set<char>());
        vector<unordered_set<char>> colcontain(9, unordered_set<char>());
        vector<unordered_set<char>> subboxcontain(9, unordered_set<char>());
        vector<vector<unordered_set<char>>> candidates(9, vector<unordered_set<char>>(9, unordered_set<char>()));

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    rowcontain[i].insert(board[i][j]);
                    colcontain[j].insert(board[i][j]);
                    subboxcontain[(i / 3) * 3 + (j / 3)].insert(board[i][j]);
                }
            }
        }

        static unordered_set<char> digits = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    candidates[i][j] = digits;
                    for(char used : rowcontain[i])
                        candidates[i][j].erase(used);
                    for(char used : colcontain[j])
                        candidates[i][j].erase(used);
                    for(char used : subboxcontain[(i / 3) * 3 + (j / 3)])
                        candidates[i][j].erase(used);
                }
            }
        }
        recurse(board, candidates);
    }

private:
    bool recurse(vector<vector<char>>& board, 
            vector<vector<unordered_set<char>>>& candidates){
        int rindex = 0, cindex = 0;
        int candicount = 10;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.' && candidates[i][j].size() < candicount){
                    rindex = i, cindex = j;
                    candicount = candidates[i][j].size();
                }
            }
        }

        if(candicount == 10) return true;

        for(auto it = candidates[rindex][cindex].begin(); it != candidates[rindex][cindex].end(); it++){
            board[rindex][cindex] = *it;
            vector<pair<int,int>> affected;

            //row
            for(int j = 0; j < 9; j++){
                if(board[rindex][j] != '.') continue;
                if(candidates[rindex][j].find(*it) != candidates[rindex][j].end()){
                    candidates[rindex][j].erase(*it);
                    affected.push_back(make_pair(rindex, j));
                }
            }

            //col
            for(int i = 0; i < 9; i++){
                if(board[i][cindex] != '.') continue;
                if(candidates[i][cindex].find(*it) != candidates[i][cindex].end()){
                    candidates[i][cindex].erase(*it);
                    affected.push_back(make_pair(i, cindex));
                }
            }

            //sub-box
            int rstart = (rindex / 3) * 3, cstart = (cindex / 3) * 3;
            for(int i = rstart; i < rstart + 3; i++){
                for(int j = cstart; j < cstart + 3; j++){
                    if(board[i][j] != '.') continue;
                    if(candidates[i][j].find(*it) != candidates[i][j].end()){
                        candidates[i][j].erase(*it);
                        affected.push_back(make_pair(i, j));
                    }
                }
            }

            if(recurse(board, candidates))
                return true;
            
            for(auto index : affected)
                candidates[index.first][index.second].insert(*it);
            board[rindex][cindex] = '.';
        }
        return false;
    }
};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        //init
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                rowcontain[i][j] = colcontain[i][j] = subboxcontain[i][j] = false;
            }
        }

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    char c = board[i][j];
                    rowcontain[i][c - '1'] = true;
                    colcontain[j][c - '1'] = true;
                    subboxcontain[(i / 3) * 3 + (j / 3)][c - '1'] = true;
                }
            }
        }

        recurse(board, 0);
    }

private:
    bool rowcontain[9][9] = { false };
    bool colcontain[9][9] = { false };
    bool subboxcontain[9][9] = { false };
    bool recurse(vector<vector<char>>& board, int index){
        while(index < 81 && board[index / 9][index % 9] != '.')
            index++;
        if(index == 81) return true;

        int row = index / 9, col = index % 9, boxindex = (row / 3) * 3 + col / 3;
        for(char c = 0; c < 9; c++){
            if(rowcontain[row][c] || colcontain[col][c] || subboxcontain[boxindex][c])
                continue;
            
            board[row][col] = c + '1';
            rowcontain[row][c] = true;
            colcontain[col][c] = true;
            subboxcontain[boxindex][c] = true;
            if(recurse(board, index + 1))
                return true;
            rowcontain[row][c] = false;
            colcontain[col][c] = false;
            subboxcontain[boxindex][c] = false;
        }
        board[row][col] = '.';
        return false;
    }
};