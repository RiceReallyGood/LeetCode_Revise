#include <vector>
using namespace std;

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<int> partner(n);
        vector<vector<int>> pref(n, vector<int>(n, 0));
        for(int i = 0; i < pairs.size(); i++){
            partner[pairs[i][0]] = pairs[i][1];
            partner[pairs[i][1]] = pairs[i][0];
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n - 1; j++){
                pref[i][preferences[i][j]] = n - j;
            }
        }

        int res = 0;
        for(int x = 0; x < n; x++){
            for(int u = 0; u < n; u++){
                if(u == x) continue;
                if(pref[x][u] > pref[x][partner[x]] && pref[u][x] > pref[u][partner[u]]){
                    res++;
                    break;
                }
            }
        }

        return res;
    }
};