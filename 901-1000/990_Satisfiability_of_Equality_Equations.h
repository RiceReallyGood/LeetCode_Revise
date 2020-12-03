#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);

        for(auto eq : equations){
            if(eq[1] == '!') continue;
            uf.merge(eq[0] - 'a', eq[3] - 'a');
        }

        for(auto& eq : equations){
            if(eq[1] == '=') continue;

            if(uf.isconnected(eq[0] - 'a', eq[3] - 'a'))
                return false;
        }

        return true;
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

        void merge(int u, int v){
            parent[root(v)] = root(u);
        }
    
    private:
        vector<int> parent;

        int root(int v){
            if(parent[v] != v)
                parent[v] = root(parent[v]);
            return parent[v];
        }
    };
};