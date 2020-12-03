#include <vector>
using namespace std;

class Solution { //Union-Find
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        this->N = edges.size();
        parent.resize(N + 1);
        for(int i = 0; i <= N; i++)
            parent[i] = i;
        
        for(int i = 0; i < N; i++){
            if(isconnected(edges[i][0], edges[i][1]))
                return edges[i];
            Union(edges[i][0], edges[i][1]);
        }
        return {0, 0};
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
};