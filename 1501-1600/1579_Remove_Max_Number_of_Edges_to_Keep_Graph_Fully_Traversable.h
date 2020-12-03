#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind uf3(n);
        int del3 = 0;
        for(auto& v : edges){
            if(v[0] == 3){
                if(uf3.isconnect(v[1] - 1, v[2] - 1))
                    del3++;
                else
                    uf3.Union(v[1] - 1, v[2] - 1);
            }
        }

        UnionFind uf1(uf3);
        int del1 = 0;
        for(auto& v : edges){
            if(v[0] == 1){
                if(uf1.isconnect(v[1] - 1, v[2] - 1))
                    del1++;
                else
                    uf1.Union(v[1] - 1, v[2] - 1);
            }
        }
        if(uf1.size() != 1)
            return -1;
        
        UnionFind uf2(uf3);
        int del2 = 0;
        for(auto& v : edges){
            if(v[0] == 2){
                if(uf2.isconnect(v[1] - 1, v[2] - 1))
                    del2++;
                else
                    uf2.Union(v[1] - 1, v[2] - 1);
            }
        }
        if(uf2.size() != 1)
            return -1;
        
        return del1 + del2 + del3;
    }

private:
    class UnionFind{
    public:
        UnionFind(int n) : parent(n), sz(n) {
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }
        UnionFind(const UnionFind& uf) : parent(uf.parent), sz(uf.size()) {}
        int size() const { return sz; }

        int Root(int node){
            if(parent[node] != node){
                parent[node] = Root(parent[node]);
            }
            return parent[node];
        }

        bool isconnect(int node1, int node2){
            return Root(node1) == Root(node2);
        }

        void Union(int node1, int node2){
            int root1 = Root(node1);
            int root2 = Root(node2);
            if(root1 != root2){
                parent[root2] = root1;
                sz--;
            }
        }
    
    private:
        vector<int> parent;
        int sz;
    };
};