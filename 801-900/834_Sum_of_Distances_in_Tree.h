#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>> graph(N);
        for(int i = 0; i < N - 1; i++){
            auto& e = edges[i];
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> res(N);
        vector<int> count(N);
        res[0] = dfs1(graph, -1, 0, count);
        dfs2(graph, -1, 0, count, res);
        return res;
    }

private:
    int dfs1(vector<vector<int>>& graph, int from, int node, vector<int>& count){
        int res = 0;
        count[node] = 1;
        for(int next : graph[node]){
            if(next != from){
                res += dfs1(graph, node, next, count);
                res += count[next];
                count[node] += count[next];
            }
        }
        return res;
    }

    void dfs2(vector<vector<int>>& graph, int from, int node, vector<int>& count, vector<int>& res){
        for(int next : graph[node]){
            if(next != from){
                res[next] = res[node] + count[0] - 2 * count[next];
                dfs2(graph, node, next, count, res);
            }
        }
    }
};