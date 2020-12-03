#include <vector>
#include <queue>
using namespace std;


//dfs with memorize
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        int maxlen = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                maxlen = max(maxlen, dfs(i, j, matrix, memo));
            }
        }
        return maxlen;
    }

private:
    int dfs(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& memo){
        if(memo[row][col] > 0) return memo[row][col];

        memo[row][col] = 1;
        if(row > 0 && matrix[row - 1][col] < matrix[row][col])
            memo[row][col] = max(memo[row][col], 1 + dfs(row - 1, col, matrix, memo));
        
        if(row < matrix.size() - 1 && matrix[row + 1][col] < matrix[row][col])
            memo[row][col] = max(memo[row][col], 1 + dfs(row + 1, col, matrix, memo));

        if(col > 0 && matrix[row][col - 1] < matrix[row][col])
            memo[row][col] = max(memo[row][col], 1 + dfs(row, col - 1, matrix, memo));
        
        if(col < matrix[0].size() - 1 && matrix[row][col + 1] < matrix[row][col])
            memo[row][col] = max(memo[row][col], 1 + dfs(row, col + 1, matrix, memo));
        
        return memo[row][col];
    }
};

//topological sort
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> adj(m * n);
        vector<int> indegree(m * n);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i > 0 && matrix[i - 1][j] < matrix[i][j]){
                    adj[i * n + j].push_back((i - 1) * n + j);
                    indegree[(i - 1) * n + j]++;
                }
                if(i < m - 1 && matrix[i + 1][j] < matrix[i][j]){
                    adj[i * n + j].push_back((i + 1) * n + j);
                    indegree[(i + 1) * n + j]++;
                }
                if(j > 0 && matrix[i][j - 1] < matrix[i][j]){
                    adj[i * n + j].push_back(i * n + j - 1);
                    indegree[i * n + j - 1]++;
                }
                if(j < n - 1 && matrix[i][j + 1] < matrix[i][j]){
                    adj[i * n + j].push_back(i * n + j + 1);
                    indegree[i * n + j + 1]++;
                }
            }
        }

        //topological sort
        queue<int> q;
        for(int i = 0; i < m * n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        int level = 0;

        while(!q.empty()){
            level++;
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                int node = q.front();
                q.pop();
                for(int next : adj[node]){
                    if(indegree[next] > 0 && --indegree[next] == 0){
                        q.push(next);
                    }
                }
            }
        }
        return level;
    }
};