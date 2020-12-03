#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int> degree(n, 0);
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }

        int cnt = n;
        while(cnt > 2){
            int sz = q.size();
            cnt -= sz;
            for(int i = 0; i < sz; i++){
                int curr = q.front();
                q.pop();
                for(int neighbour : adj[curr]){
                    if(--degree[neighbour] == 1)
                        q.push(neighbour);
                }
            }
        }

        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};