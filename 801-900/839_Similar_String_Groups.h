#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int n = A.size(), len = A[0].size();
        UnionFind uf(n);

        if(n < len * len){
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    if(uf.isconnect(i, j)) continue;

                    if(isSimilar(A[i], A[j]))
                        uf.Union(i, j);
                }
            }
        }
        else{
            unordered_map<string, int> index;
            for(int i = 0; i < n; i++) index[A[i]] = i;

            for(int i = 0; i < n; i++){
                string& temp = A[i];
                for(int j = 0; j < len; j++){
                    for(int k = j + 1; k < len; k++){
                        swap(temp[j], temp[k]);
                        if(index.find(temp) != index.end())
                            uf.Union(i, index[temp]);
                        swap(temp[j], temp[k]);
                    }
                }
            }
        }

        return uf.size();
    }

private:
    class UnionFind{
    public:
        UnionFind(int n) : sz (n), parent(n){
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }

        void Union(int u, int v){
            int ru = root(u);
            int rv = root(v);
            if(ru != rv){
                parent[rv] = ru;
                --sz;
            }
        }

        bool isconnect(int u, int v){
            return root(u) == root(v);
        }

        int size() { return sz; }
    
    private:
        int sz;
        vector<int> parent;

        int root(int v){
            if(parent[v] != v){
                parent[v] = root(parent[v]);
            }
            return parent[v];
        }
    };

    bool isSimilar(const string& s1, const string& s2){
        int diff = 0;
        for(int i = 0; i < s1.length(); i++){
            if(s1[i] != s2[i] && ++diff > 2)
                return false;
        }
        return true;
    }
};