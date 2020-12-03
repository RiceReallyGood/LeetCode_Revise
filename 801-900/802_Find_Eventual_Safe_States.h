#include <vector>
#include <queue>
using namespace std;

class Solution { //dfs
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, -1);
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(dfs(graph, i, state))
                res.push_back(i);
        }
        return res;
    }

private:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& state){
        if(state[node] != -1) return state[node];

        state[node] = 0;
        for(int next : graph[node]){
            if(state[next] == 1) continue;

            if(!dfs(graph, next, state)){
                return state[node] = 0;
            }
        }

        return state[node] = 1;
    }
};

class Solution { //Topological sort
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rgraph(n);
        vector<int> outdegree(n, 0);
        for(int i = 0; i < n; i++){
            outdegree[i] = graph[i].size();
            for(int j : graph[i]){
                rgraph[j].push_back(i);
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(outdegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v : rgraph[u]){
                if(--outdegree[v] == 0){
                    q.push(v);
                }
            }
        }

        vector<int> res;
        for(int i = 0; i < n; i++){
            if(outdegree[i] == 0){
                res.push_back(i);
            }
        }
        return res;
    }
};