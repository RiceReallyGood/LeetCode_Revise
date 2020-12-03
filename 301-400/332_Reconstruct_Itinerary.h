#include <vector>
#include <set>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        if(tickets.empty()) return {};
        this->n = tickets.size() + 1;
        set<string> airportset;
        for(int i = 0; i < tickets.size(); i++){
            airportset.insert(tickets[i][0]);
            airportset.insert(tickets[i][1]);
        }
        vector<string> airports(airportset.begin(), airportset.end());
        unordered_map<string, int> index;
        for(int i = 0; i < airports.size(); i++)
            index[airports[i]] = i;
        
        vector<vector<int>> adj(airports.size());
        vector<vector<bool>> used(airports.size());
        for(int i = 0; i < tickets.size(); i++){
            adj[index[tickets[i][0]]].push_back(index[tickets[i][1]]);
            used[index[tickets[i][0]]].push_back(false);
        }
        for(int i = 0; i < airports.size(); i++){
            sort(adj[i].begin(), adj[i].end());
        }
        vector<int> path;
        dfs(adj, index["JFK"], used, path);

        vector<string> ret;
        for(int i = 0; i < n; i++)
            ret.push_back(airports[path[i]]);
        return ret;
    }

private:
    int n;
    bool dfs(vector<vector<int>>& adj, int node, vector<vector<bool>>& used, vector<int>& path){
        path.push_back(node);
        if(path.size() == this->n) return true;

        for(int i = 0; i < adj[node].size(); i++){
            if(!used[node][i]){
                used[node][i] = true;
                if(dfs(adj, adj[node][i], used, path))
                    return true;
                used[node][i] = false;
            }
        }

        path.pop_back();
        return false;
    }
};