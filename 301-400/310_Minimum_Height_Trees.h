#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int> connections(n);
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            connections[edges[i][0]]++;
            connections[edges[i][1]]++;

            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> eles;
        for(int i = 0; i < n; i++){
            if(connections[i] == 1)
                eles.push_back(i);
        }

        while(true){
            vector<int> nextleveleles;
            for(int node : eles){
                for(int next : adj[node]){
                    if(connections[next] == 2)
                        nextleveleles.push_back(next);
                    connections[next]--;
                }
            }

            if(nextleveleles.empty())
                return eles;
            swap(eles, nextleveleles);
        }
        return {};
    }
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int> connections(n);
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            connections[edges[i][0]]++;
            connections[edges[i][1]]++;

            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        queue<int> eles;
        for(int i = 0; i < n; i++){
            if(connections[i] == 1)
                eles.push(i);
        }

        int rst = n;
        while(rst > 2){
            int levelcount = eles.size();
            rst -=levelcount;
            for(int i = 0; i < levelcount; i++){
                int node = eles.front();
                eles.pop();
                for(int next : adj[node]){
                    if(connections[next] == 2)
                        eles.push(next);
                    connections[next]--;
                }
            }
        }

        vector<int> ret;
        while(!eles.empty()){
            ret.push_back(eles.front());
            eles.pop();
        }
        return ret;
    }
};