#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        this->N = edges.size();
        parent.resize(N + 1);
        for(int i = 0; i <= N; i++)
            parent[i] = i;
        vector<int> indegree(N + 1, 0);

        int loopindex = -1, secondinindex = -1;
        for(int i = 0; i < N; i++){
            if(isconnected(edges[i][0], edges[i][1]))
                loopindex = i;
            Union(edges[i][0], edges[i][1]);
            if(indegree[edges[i][1]] == 1)
                secondinindex = i;
            indegree[edges[i][1]]++;
        }

        int rootindex = 0;
        for(int i = 1; i <= N; i++){
            if(indegree[i] == 0) rootindex = i;
        }

        if(rootindex == 0) return edges[loopindex];
        
        vector<vector<int>> adj(N + 1);
        for(int i = 0; i < N; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        vector<int> res = {0, 0};
        if(dfs(adj, edges[secondinindex][1], edges[secondinindex][1],res)){
            return res;
        }

        return edges[secondinindex];
    }

private:
    int N;
    vector<int> parent;

    int root(int v){
        if(parent[v] != v){
            parent[v] = root(parent[v]);
        }
        return parent[v];
    }

    bool isconnected(int u, int v){
        return root(u) == root(v);
    }

    void Union(int u, int v){
        parent[root(v)] = root(u);
    }

    bool dfs(vector<vector<int>>& adj,int u, int root, vector<int>& res){
        for(int v : adj[u]){
            if(v == root){
                res[0] = u, res[1] = v;
                return true;
            }
            if(dfs(adj, v, root, res))
                return true;
        }
        return false;
    }
};


class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        UnionFind uf(N + 1);

        vector<int> parent(N + 1);
        for(int i = 0; i <= N; i++) parent[i] = i;


        int conflict = -1, cycle = -1;
        for(int i = 0; i < N; i++){
            vector<int>& e = edges[i];
            if(parent[e[1]] != e[1]){
                conflict = i;
            }
            else{
                parent[e[1]] = e[0];
                if(uf.isconnected(e[0], e[1])){
                    cycle = i;
                }
                else{
                    uf.Union(e[0], e[1]);
                }
            }
        }

        if(conflict == -1){
            return edges[cycle];
        }
        else{
            if(cycle == -1){
                return edges[conflict];
            }
            else{
                return {parent[edges[conflict][1]], edges[conflict][1]};
            }
        }
    }

private:
    class UnionFind{
    public:
        UnionFind(int n) : parent(n) {
            for(int i = 0; i < n; i++)
                parent[i] = i;
        }

        bool isconnected(int u, int v){
            return root(u) == root(v);
        }

        void Union(int u, int v){
            parent[root(v)] = root(u);
        }

    private:
        vector<int> parent;
        int root(int u){
            if(parent[u] != u)
                parent[u] = root(parent[u]);
            
            return parent[u];
        }
    };
};