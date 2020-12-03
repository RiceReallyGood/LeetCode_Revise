#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> adj(N), weight(N);
        for(int i = 0; i < times.size(); i++){
            vector<int>& edge = times[i];
            adj[edge[0] - 1].push_back(edge[1] - 1);
            weight[edge[0] - 1].push_back(edge[2]);
        }

        vector<int> dist(N, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, K - 1});

        while(!pq.empty()){
            int currdist = pq.top().first, node = pq.top().second;
            pq.pop();
            if(currdist > dist[node]) continue;
            dist[node] = currdist;
            for(int i = 0; i < adj[node].size(); i++){
                int next = adj[node][i], w = weight[node][i];
                if(currdist + w < dist[next]){
                    dist[next] = currdist + w;
                    pq.push({dist[next], next});
                }
            }
        }

        int res = 0;
        for(int i = 0; i < N; i++)
            res = max(res, dist[i]);
        
        return res == INT_MAX ? -1 : res;
    }
};