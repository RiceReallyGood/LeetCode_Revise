#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind variables(26);
        vector<int> nonequals;
        for(int i = 0; i < equations.size(); i++){
            if(equations[i][1] == '!')
                nonequals.push_back(i);
            else
                variables.Union(equations[i][0] - 'a', equations[i][3] - 'a');
        }

        for(int i = 0; i < nonequals.size(); i++){
            if(variables.isConnected(equations[nonequals[i]][0] - 'a', equations[nonequals[i]][3] - 'a'))
                return false;
        }
        return true;
    }

private:
    class UnionFind{
    public:
        UnionFind(int n): uf(n) {
            for(int i = 0; i < n; i++)
                uf[i] = i;
        }

        int root(int v){
            while(uf[v] != v){
                uf[v] = uf[uf[v]];
                v = uf[v];
            }
            return v;
        }

        bool isConnected(int v1, int v2){
            return root(v1) == root(v2);
        }

        void Union(int v1, int v2){
            int root1 = root(v1);
            int root2 = root(v2);
            if(root1 != root2)
                uf[root2] = root1;
        }
    
    private:
        vector<int> uf;
    };
};