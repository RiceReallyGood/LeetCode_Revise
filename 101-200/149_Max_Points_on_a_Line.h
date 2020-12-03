#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ret = 0;
        for(int i = 0; i < n - ret; i++){
            int duplicated = 1;
            map<pair<int, int>, int> linepoints;
            for(int j = i + 1; j < n; j++){
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    duplicated++;
                else{
                    int dx = points[j][0] - points[i][0];
                    int dy = points[j][1] - points[i][1];
                    int g = gcd(dx, dy);
                    ++linepoints[{dx / g, dy / g}];
                }
            }
            ret = max(ret, duplicated);
            for(auto it = linepoints.begin(); it != linepoints.end(); it++){
                ret = max(ret, duplicated + it->second);
            }
        }
        return ret;
    }

private:
    int gcd(int a, int b){
        while(b){
            swap(a, b);
            b %= a;
        }
        return a;
    }
};