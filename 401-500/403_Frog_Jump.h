#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        if(stones.size() == 2) return true;
        int n = stones.size();
        for(int i = 3; i < n; i++) {
            if(stones[i] > stones[i - 1] * 2) {
                return false; 
            }
        }
        unordered_map<int, int> index;
        for(int i = 0; i < n; i++) index[stones[i]] = i;

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        dp[0][1] = true;

        set<int> s = {1};

        while(!s.empty()){
            int i = *s.begin();
            s.erase(i);
            for(int j = i + 1; j < n; j++){
                int prev = stones[i] - (stones[j] - stones[i]) - 1;
                for(int k = 0; k < 3; k++){
                    if(index.find(prev + k) != index.end() && dp[index[prev + k]][i]){
                        dp[i][j] = true;
                        s.insert(j);
                        break;
                    }
                }

                if(j == n - 1 && dp[i][j]) return true;
            }
        }
        return false;
    }
};