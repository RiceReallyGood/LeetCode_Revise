#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        int n = points.size();
        vector<int> dist(n, INT_MAX);
        vector<int> visited(n, false);
        dist[0] = 0;

        for(int it = 0; it < n; it++){
            int mindistid = -1, mindist = INT_MAX;
            for(int i = 0; i < n; i++){
                if(visited[i]) continue;
                if(dist[i] < mindist){
                    mindist = dist[i];
                    mindistid = i;
                }
            }

            visited[mindistid] = true;

            for(int i = 0; i < n; i++){
                if(visited[i]) continue;

                dist[i] = min(dist[i], abs(points[i][0] - points[mindistid][0]) + abs(points[i][1] - points[mindistid][1]));
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++)
            res += dist[i];
        return res;
    }
};