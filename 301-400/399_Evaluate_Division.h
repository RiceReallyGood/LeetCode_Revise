#include <vector>
#include <string>
#include <limits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> index;
        for(int i = 0; i < equations.size(); i++){
            if(index.find(equations[i][0]) == index.end()){
                int n = index.size();
                index[equations[i][0]] = n;
                uf.push_back(n);
                fact.push_back(1.);
            }
            if(index.find(equations[i][1]) == index.end()){
                int n = index.size();
                index[equations[i][1]] = n;
                uf.push_back(n);
                fact.push_back(1.);
            }

            Union(index[equations[i][0]], index[equations[i][1]], values[i]);
        }

        vector<double> ret;

        for(int i = 0; i < queries.size(); i++){
            if(index.find(queries[i][0]) == index.end() || 
               index.find(queries[i][1]) == index.end()){
                ret.push_back(-1);
                continue;
            }
            if(fact[index[queries[i][0]]] == 0){
                ret.push_back(0);
                continue;
            }
            if(!isconnected(index[queries[i][0]], index[queries[i][1]])){
                ret.push_back(-1);
                continue;
            }

            ret.push_back(fact[index[queries[i][0]]] / fact[index[queries[i][1]]]);
        }
        return ret;
    }

private:
    vector<int> uf;
    vector<double> fact;

    int root(int v){
        if(v != uf[v]){
            int r = root(uf[v]);
            fact[v] = fact[v] * fact[uf[v]];
            uf[v] = r;
        }
        return uf[v];
    }

    bool isconnected(int v1, int v2){
        return root(v1) == root(v2);
    }

    void Union(int v1, int v2, double k){
        if(k < std::numeric_limits<double>::epsilon()){
            fact[v1] = 0;
            return;
        }
        int r1 = root(v1);
        int r2 = root(v2);

        if(r1 != r2){
            uf[r1] = r2;
            fact[r1] = k * fact[v2] / fact[v1];
        }
    }
};