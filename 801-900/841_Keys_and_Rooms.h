#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> inqueue(n, false);
        queue<int> q;
        q.push(0);
        inqueue[0] = true;

        int cnt = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cnt++;

            for(int v : rooms[u]){
                if(!inqueue[v]){
                    q.push(v);
                    inqueue[v] = true;
                }
            }
        }

        return cnt == rooms.size();
    }
};