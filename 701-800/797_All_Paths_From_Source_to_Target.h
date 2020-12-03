#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<int>>> paths(n);
        dfs(graph, 0, paths);

        for(int i = 0; i < paths[0].size(); i++){
            reverse(paths[0][i].begin(), paths[0][i].end());
        }

        return paths[0];
    }

private:
    void dfs(vector<vector<int>>& graph, int node, vector<vector<vector<int>>>& paths){
        if(!paths[node].empty()) return;
        if(node == graph.size() - 1){
            paths[node].push_back({node});
            return;
        }

        for(int next : graph[node]){
            dfs(graph, next, paths);
            for(auto& path : paths[next]){
                paths[node].push_back(path);
                paths[node].back().push_back(node);
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(graph, 0, path, res);
        return res;
    }

private:
    void dfs(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& paths){
        path.push_back(node);
        if(node == graph.size() - 1){
            paths.emplace_back(path);
            path.pop_back();
            return;
        }

        for(int next : graph[node]){
            dfs(graph, next, path, paths);
        }

        path.pop_back();
    }
};