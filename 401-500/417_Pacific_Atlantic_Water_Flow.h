#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return {};
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<char>> ToPacific(m, vector<char>(n, ' '));
        vector<vector<char>> ToAtlantic(m, vector<char>(n, ' '));

        for(int i = 0; i < m; i++) dfs(matrix, i, 0, ToPacific, 'p');
        for(int j = 1; j < n; j++) dfs(matrix, 0, j, ToPacific, 'p');

        for(int i = 0; i < m; i++) dfs(matrix, i, n - 1, ToAtlantic, 'a');
        for(int j = 0; j < n - 1; j++) dfs(matrix, m - 1, j, ToAtlantic, 'a');

        vector<vector<int>> ret;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(ToPacific[i][j] == 'p' && ToAtlantic[i][j] == 'a')
                    ret.push_back({i, j});
            }
        }
        return ret;
    }

private:
    void dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<char>>& res, char mark){
        if(res[i][j] == mark) return;

        res[i][j] = mark;
        if(i > 0 && matrix[i - 1][j] >= matrix[i][j]) dfs(matrix, i - 1, j, res, mark);
        if(i < matrix.size() - 1 && matrix[i + 1][j] >= matrix[i][j]) dfs(matrix, i + 1, j, res, mark);
        if(j > 0 && matrix[i][j - 1] >= matrix[i][j]) dfs(matrix, i, j - 1, res, mark);
        if(j < matrix[0].size() - 1 && matrix[i][j + 1] >= matrix[i][j]) dfs(matrix, i, j + 1, res, mark);
    }
};