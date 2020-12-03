#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string crackSafe(int n, int k) {
        this->k = k;
        this->totalnums = std::pow(k, n);
        this->mod = std::pow(10, n - 1);
        int len = std::pow(10, n);
        vector<vector<bool>> used(len, vector<bool>(k, false));
        vector<bool> visited(len, false);

        vector<int> path;
        dfs(visited, used, 0, path);
        string res(n, '0');
        for(int i = 1; i < path.size(); i++)
            res.push_back('0' + path[i] % 10);
        return res;
    }

private:
    int mod;
    int k;
    int totalnums;
    bool dfs(vector<bool>& visited, vector<vector<bool>>& used, int node, vector<int>& path){
        path.push_back(node);
        visited[node] = true;
        if(path.size() == totalnums)
            return true;

        int prefix = node % mod * 10;
        for(int i = 0; i < k; i++){
            if(!visited[prefix + i] && !used[node][i]){
                used[node][i] = true;
                if(dfs(visited, used, prefix + i, path))
                    return true;
                used[node][i] = false;
            }
        }
        
        path.pop_back();
        visited[node] = false;
        return false;
    }
};

class Solution {
public:
    string crackSafe(int n, int k) {
        int kn = std::pow(k, n), kn_1 = std::pow(k, n - 1);
        vector<int> out(kn_1, k);

        int curr = 0;
        string res(n + kn - 1, '0');
        for(int i = 0; i < kn; i++){
            res[i + n - 1] = '0' + (--out[curr]);
            curr = (curr * k + out[curr]) % kn_1;
        }

        return res;
    }
};

class Solution {
public:
    string crackSafe(int n, int k) {
        this->kn_1 = std::pow(k, n - 1);
        vector<int> out(kn_1, 0);
        string res;
        dfs(out, 0, res);
        res += string(n - 1, '0');
        reverse(res.begin(), res.end());
        return res;
    }

private:
    int k;
    int kn_1;
    void dfs(vector<int>& out, int node, string& res){
        while(out[node] < k){
            char c = '0' + (out[node]);
            dfs(out, (node * this->k + out[node]++) % this->kn_1, res);
            res.push_back(c);
        }
    }
};