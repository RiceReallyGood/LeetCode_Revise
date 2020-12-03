#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    int chaseGame(vector<vector<int>>& edges, int startA, int startB) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            adj[edges[i][0] - 1].push_back(edges[i][1] - 1);
            adj[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }

        if(isconnect(adj, startA, startB))
            return 1;

        vector<int> degree(n, 0);
        for(int i = 0; i < n; i++){
            degree[edges[i][0] - 1]++;
            degree[edges[i][1] - 1]++;
        }
        int internode = -1, outnode = -1;
        for(int i= 0; i < n; i++){
            if(degree[i] == 3)
                internode = i;

            if(degree[i] == 1)
                outnode = i;
        }
        if(internode == -1)
            return -1;


        vector<bool> inloop(n, false);
        findloop(adj, inloop, internode, internode);

        if(!inloop[startB - 1]){
            int distA = dist(adj, internode, startA - 1);
            int distB = dist(adj, internode, startB - 1);
            int distout =  dist(adj, internode, outnode);

            if(!inloop[startA - 1]){
                if(distA > distB)
                    return -1;
                return distout - distA;
            }
            else{
                return distout + distA;
            }
        }
        else{
            return -1;
        }
    }

private:
    bool isconnect(vector<vector<int>>& adj, int n1, int n2){
        for(int next : adj[n1]){
            if(next == n2)
                return true;
        }
        return false;
    }
    bool findloop(vector<vector<int>>& adj, vector<bool>& visited, int target, int curr){
        visited[curr] == true;

        for(int next : adj[curr]){
            if(!visited[next]){
                if(findloop(adj, visited, target, next))
                    return true;
            }
        }

        if(curr == target) return true;
        visited[curr] = false;
        return false;
    }

    int dist(vector<vector<int>>& adj, int start, int target){
        queue<int> q;
        q.push(start);
        int d = 0;
        int n = adj.size();
        vector<bool> visited(n, false);
        visited[start] = true;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < n; i++){
                int curr = q.front();
                q.pop();
                if(curr == target) return d;
                for(int next : adj[curr]){
                    if(!visited[next]){
                        q.push(next);
                        visited[next];
                    }
                }
            }
            d++;
        }
        return -1;
    }
};