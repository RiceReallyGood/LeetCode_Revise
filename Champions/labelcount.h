#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < n - 1; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<int>> childs(n);
        BuildTree(0, adj, -1, childs);
        vector<int> count(26, 0);
        vector<int> ans(n);
        recurse(0, childs, labels, count, ans);
        return ans;
    }

private:
    void BuildTree(int node, vector<vector<int>>& adj, int parent, vector<vector<int>>& childs){
        for(int neighbour : adj[node]){
            if(neighbour != parent){
                childs[node].push_back(neighbour);
                BuildTree(neighbour, adj, node, childs);
            }
        }
    }

    void recurse(int node, vector<vector<int>>& childs, string& labels, vector<int>& count, vector<int>& ans){
        for(int child : childs[node]){
            vector<int> temp(26, 0);
            recurse(child, childs, labels,temp, ans);
            for(int i = 0; i < 26; i++)
                count[i] += temp[i];
        }
        count[labels[node] - 'a']++;
        ans[node] = count[labels[node] - 'a'];
    }
};