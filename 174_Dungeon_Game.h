#include <vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty() || dungeon[0].empty()) return -1;
        int m = dungeon.size(), n = dungeon[0].size();
        dungeon[m - 1][n - 1] = 1 + max(0, -dungeon[m - 1][n - 1]);
        for(int j = n - 2; j >= 0; j--){
            dungeon[m - 1][j] = max(1, dungeon[m - 1][j + 1] - dungeon[m - 1][j]);
        }

        for(int i = m - 2; i >= 0; i--){
            dungeon[i][n - 1] = max(1, dungeon[i + 1][n - 1] - dungeon[i][n - 1]);
            for(int j = n - 2; j >= 0; j--){
               dungeon[i][j] = max(1, min(dungeon[i][j + 1], dungeon[i + 1][j]) - dungeon[i][j]);
            }
        }

        return dungeon[0][0];
    }
};