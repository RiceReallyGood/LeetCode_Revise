#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> nums;
        while(nums.find(n) == nums.end()){
            nums.insert(n);
            n = DigitSquareSum(n);
        }
        return n == 1;
    }

private:
    int DigitSquareSum(int n){
        int ret = 0;
        while(n){
            int digit = n % 10;
            n /= 10;
            ret += digit * digit;
        }
        return ret;
    }
};