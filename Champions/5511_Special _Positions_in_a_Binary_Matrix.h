#include <vector>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty())
            return 0;
        
        int n = mat.size(), m = mat[0].size();
        vector<int> countrows(m), countcols(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                    countrows[j]++;
                    countcols[i]++;
                }
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1 && countcols[i] == 1 && countrows[j] == 1)
                    res++;
            }
        }
        return res;
    }
};