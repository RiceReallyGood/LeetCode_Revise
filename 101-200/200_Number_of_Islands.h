#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size();

        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }

private:
    void dfs(vector<vector<char>>& grid, int row, int col){
        grid[row][col] = '.';

        if(row > 0 && grid[row - 1][col] == '1')
            dfs(grid, row - 1, col);

        if(row < grid.size() - 1 && grid[row + 1][col] == '1')
            dfs(grid, row + 1, col);
        
        if(col > 0 && grid[row][col - 1] == '1')
            dfs(grid, row, col - 1);
        
        if(col < grid[0].size() - 1 && grid[row][col + 1] == '1')
            dfs(grid, row, col + 1);
    }
};