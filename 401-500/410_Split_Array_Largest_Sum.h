#include <vector>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<long> partialsum(n);
        partialsum[0] = nums[0];
        for(int i = 1; i < n; i++)
            partialsum[i] = partialsum[i - 1] + nums[i];

        vector<long> dp = partialsum;


        for(int piece = 2; piece <= m; piece++){
            vector<long> temp = dp;
            for(int i = piece - 1; i < n; i++){
                int l = piece - 2, r = i;

                //find the smallest index l, such that dp[l] >= sum over (l, i]
                while(l < r){
                    int c = l + (r - l) / 2;
                    if(temp[c] < partialsum[i] - partialsum[c])
                        l = c + 1;
                    else
                        r = c;
                }

                if(l != i) dp[i] = max(temp[l], partialsum[i] - partialsum[l]);
                if(l != piece - 2) dp[i] = min(dp[i], max(temp[l - 1], partialsum[i] - partialsum[l - 1]));
            }
        }

        return dp[n - 1];
    }
};