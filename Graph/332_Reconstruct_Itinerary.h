#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        if(tickets.empty()) return {};
        this->n = tickets.size() + 1;
        set<string> airportset;
        airportset.insert("JFK");
        for(int i = 0; i < tickets.size(); i++){
            airportset.insert(tickets[i][1]);
        }
        vector<string> airports(airportset.begin(), airportset.end());

        unordered_map<string, int> index;
        for(int i = 0; i < airports.size(); i++)
            index[airports[i]] = i;

        vector<vector<int>> adj(index.size());
        for(int i = 0; i < tickets.size(); i++){
            adj[index[tickets[i][0]]].push_back(index[tickets[i][1]]);
        }
        vector<vector<bool>> used;
        for(int i= 0; i < adj.size(); i++){
            sort(adj[i].begin(), adj[i].end());
            used.push_back(vector<bool>(adj[i].size(), false));
        }
        
        vector<int> path;
        dfs(adj, used, index["JFK"], path);

        vector<string> res;
        for(int i = 0; i < path.size(); i++)
            res.push_back(airports[path[i]]);
        
        return res;
    }

private:
    int n;
    bool dfs(vector<vector<int>>& adj, vector<vector<bool>>& used, int node, vector<int>& path){
        path.push_back(node);
        if(path.size() == this->n)
            return true;
        
        for(int i = 0; i < adj[node].size(); i++){
            if(!used[node][i]){
                used[node][i] = true;
                if(dfs(adj, used, adj[node][i], path))
                    return true;
                used[node][i] = false;
            }
        }

        path.pop_back();
        return false;
    }
};

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        if(tickets.empty()) return {};
        this->n = tickets.size() + 1;
        unordered_map<string, vector<string>> adj;
        unordered_map<string, vector<bool>> used;

        for(int i = 0; i < tickets.size(); i++){
            adj[tickets[i][0]].push_back(tickets[i][1]);
            used[tickets[i][0]].push_back(false);
        }

        for(auto it : adj){
            sort(adj[it.first].begin(), adj[it.first].end());
        }

        vector<string> path;
        dfs(adj, used, "JFK", path);
        return path;
    }

private:
    int n;

    bool dfs(unordered_map<string, vector<string>>& adj, unordered_map<string, vector<bool>>& used, string airport, vector<string>& path){
        path.push_back(airport);
        if(path.size() == this->n)
            return true;
        
        vector<string>& next = adj[airport];
        vector<bool>& visited = used[airport];
        for(int i = 0; i < next.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                if(dfs(adj, used, next[i], path))
                    return true;
                visited[i] = false;
            }
        }

        path.pop_back();
        return false;
    }
};