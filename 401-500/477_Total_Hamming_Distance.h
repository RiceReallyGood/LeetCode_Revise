#include <vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) { //TLE
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                res += HammingDistance(nums[i], nums[j]);
            }
        }
        return res;
    }

private:
    int HammingDistance(const int& a, const int& b){
        int dist = a ^ b;
        int res = 0;
        while(dist){
            dist = dist & (dist - 1);
            res++;
        }
        return res;
    }
};

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < 31; i++){
            int ones = 0;
            for(int i = 0; i < n; i++){
                ones += nums[i] & 1;
                nums[i] >>= 1;
            }
            res += ones * (n - ones);
        }
        return res;
    }
};