#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;

        for(int sum = 0; sum < m + n - 1; sum++){
            if(sum % 2 == 0){
                int b = min(sum, m - 1), e = max(0, sum + 1 - n);
                for(int i = b; i >= e; i--)
                    res.push_back(matrix[i][sum - i]);
            }
            else{
                int b = max(0, sum + 1 - n), e = min(sum, m - 1);
                for(int i = b; i <= e; i++)
                    res.push_back(matrix[i][sum - i]);
            }
        }
        return res;
    }
};