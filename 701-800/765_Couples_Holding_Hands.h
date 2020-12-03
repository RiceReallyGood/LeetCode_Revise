#include <vector>
using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int N = row.size();
        vector<int> index(N, -1);
        vector<int> partner(N);
        for(int i = 0; i < N; i++)  partner[i] = i ^ 1;

        for(int i = 0; i < N; i++) index[row[i]] = i;
        
        int res = 0;
        for(int i = 0; i < N; i += 2){
            if(row[i + 1] == partner[row[i]])
                continue;
            
            int target = partner[row[i]];
            while(row[i + 1] != target){
                swap(row[i + 1], row[partner[index[partner[row[i + 1]]]]]);
                res++;
            }
        }
        return res;
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        UnionFind uf(n);

        for(int i = 0; i < n * 2; i += 2){
            uf.Union(row[i] / 2, row[i - 1] / 2);
        }

        return n - uf.size();
    }

private:
    class UnionFind{
    public:
        UnionFind(int n) : sz(n), parent(n) {
            for(int i= 0; i < n; i++)
                parent[i] = i;
        }

        void Union(int u, int v){
            int ru = root(u);
            int rv = root(v);
            if(ru != rv){
                parent[rv] = ru;
                sz--;
            }
        }

        int size() { return sz;}

    private:
        int sz;
        vector<int> parent;

        int root(int v){
            if(parent[v] != v)
                parent[v] = root(parent[v]);
            
            return parent[v];
        }
    };
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int N = row.size();
        vector<int> index(N, -1);
        vector<int> partner(N);
        for(int i = 0; i < N; i++)  partner[i] = i ^ 1;

        for(int i = 0; i < N; i++) index[row[i]] = i;
        
        int res = 0;
        for(int i = 0; i < N; i += 2){
            if(row[i + 1] == partner[row[i]])
                continue;
            
            int j = index[partner[row[i]]];
            swap(row[i + 1], row[j]);
            swap(index[row[i + 1]], index[row[j]]);
            res++;
        }
        return res;
    }
};
