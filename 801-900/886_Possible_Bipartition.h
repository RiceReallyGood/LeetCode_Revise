#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N);
        for(int i = 0; i < dislikes.size(); i++){
            auto& e = dislikes[i];
            graph[e[0] - 1].push_back(e[1] - 1);
            graph[e[1] - 1].push_back(e[0] - 1);
        }

        vector<int> state(N, -1);

        for(int i = 0; i < N; i++){
            if(state[i] == -1){
                queue<int> q;
                q.push(i);
                state[i] = 0;
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    for(int v : graph[u]){
                        if(state[v] == state[u]) return false;
                        if(state[v] == -1){
                            q.push(v);
                            state[v] = 1 - state[u];
                        }
                    }
                }
            }
        }
        return true;
    }
};