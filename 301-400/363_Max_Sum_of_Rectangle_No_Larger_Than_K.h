#include <vector>
#include <set>
#include <climits>
using namespace std;


class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> rowsum(m, vector<int>(n + 1, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                rowsum[i][j + 1] = rowsum[i][j] + matrix[i][j];
            }
        }

        int ret = INT_MIN;
        for(int j2 = 0; j2 < n; j2++){
            for(int j1 = 0; j1 <= j2; j1++){
                set<int> sums = {0};
                int sum = 0;
                for(int i = 0; i < m; i++){
                    sum += rowsum[i][j2 + 1] - rowsum[i][j1];
                    auto it = sums.lower_bound(sum - k);
                    if(it != sums.end()){
                        ret = max(ret, sum - *it);
                        if(ret == k) return ret;
                    }
                    sums.insert(sum);
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();

        int ret = INT_MIN;
        if(m < n){
            for(int j1 = 0; j1 < n; j1++){
                vector<int> rowsum(m, 0);
                for(int j2 = j1; j2 < n; j2++){
                    for(int i = 0; i < m; i++)
                        rowsum[i] += matrix[i][j2];
                    
                    int sum = 0;
                    set<int> sums = {0};
                    for(int i = 0; i < m; i++){
                        sum += rowsum[i];
                        auto it = sums.lower_bound(sum - k);
                        if(it != sums.end()){
                            ret = max(ret, sum - *it);
                            if(ret == k) return ret;
                        }
                        sums.insert(sum);
                    }
                }
            }
        }
        else{
            for(int i1 = 0; i1 < m; i1++){
                vector<int> colsum(n, 0);
                for(int i2 = i1; i2 < m; i2++){
                    for(int j = 0; j < n; j++)
                        colsum[j] += matrix[i2][j];
                    
                    int sum = 0;
                    set<int> sums = {0};
                    for(int j = 0; j < n; j++){
                        sum += colsum[j];
                        auto it = sums.lower_bound(sum - k);
                        if(it != sums.end()){
                            ret = max(ret, sum - *it);
                            if(ret == k) return ret;
                        }
                        sums.insert(sum);
                    }
                }
            }
        }
        return ret;
    }
};