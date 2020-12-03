#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int minprod = 1, maxprod = 1;
        int ret = INT_MIN;
        for(int num : nums){
            if(num < 0) swap(minprod, maxprod);
            minprod = min(minprod * num, num);
            maxprod = max(maxprod * num, num);
            ret = max(ret, maxprod);
        }
        return ret;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int minprod = 1, maxprod = 1;
        int ret = INT_MIN;
        for(int num : nums){
            if(num == 0)
                minprod = maxprod = 0;
            else if(num > 0){
                maxprod = maxprod > 0 ? maxprod * num : num;
                minprod = minprod < 0 ? minprod * num : num;
            }
            else{
                int temp = maxprod;
                maxprod = minprod < 0 ? minprod * num : num;
                minprod = temp > 0 ? temp * num : num;
            }
            ret = max(ret, maxprod);
        }
        return ret;
    }
};