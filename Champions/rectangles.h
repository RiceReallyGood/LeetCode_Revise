#include <vector>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty()) return 0;
        int m = mat.size(), n = mat[0].size();
        vector<int> h(n, 0);
        int ret = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0) h[j] = 0;
                else h[j]++;
            }


            for(int j = 0; j < n; j++){
                int minheight = h[j];
                for(int k = j; k >= 0; k--){
                    if(h[k] < minheight) minheight = h[k];
                    ret += minheight;
                }
            }
        }
        return ret;
    }
};