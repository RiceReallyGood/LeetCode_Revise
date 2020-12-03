#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();
        UnionFind uf(2 * N * (N + 1));

        for(int i = 0; i < N; i++){
            int u = i * (2 * N + 1), l = u + N, r = l + 1, d = r + N;
            for(int j = 0; j < N; j++){
                if(grid[i][j] == ' '){
                    uf.merge(u, l);
                    uf.merge(u, r);
                    uf.merge(l, d);
                }
                else if(grid[i][j] == '/'){
                    uf.merge(u, l);
                    uf.merge(r, d);
                }
                else{
                    uf.merge(u, r);
                    uf.merge(l, d);
                }
                ++u, ++l, ++r, ++d;
            }
        }

        return uf.size();
    }

private:
    class UnionFind{
    public:
        UnionFind(int n) : parent(n), sz(n) {
            for(int i = 0; i < n; i++)
                parent[i] = i;
        }

        void merge(int u, int v){
            int ru = root(u);
            int rv = root(v);
            if(ru != rv){
                parent[rv] = ru;
                sz--;
            }
        }

        int size() { return sz; }
    
    private:
        vector<int> parent;
        int sz;

        int root(int v){
            if(parent[v] != v)
                parent[v] = root(parent[v]);
            return parent[v];
        }
    };
};