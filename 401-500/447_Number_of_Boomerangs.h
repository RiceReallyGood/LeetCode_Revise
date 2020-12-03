#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        int n = points.size();
        for(int i = 0; i < n; i++){
            unordered_map<int, int> count;
            for(int j = 0; j < n; j++){
                if(j == i) continue;
                count[(points[i][0] - points[j][0]) * (points[i][0] - points[j][0])
                      + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1])]++;
            }

            for(auto it = count.begin(); it != count.end(); it++){
                res += it->second * (it->second - 1);
            }
        }
        return res;
    }
};