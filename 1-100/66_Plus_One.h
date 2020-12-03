#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1, index = digits.size() - 1;
        while(index >= 0 && digits[index] == 9){
            digits[index--] = 0;
        }
        if(index == -1)
            digits.insert(digits.begin(), 1);
        else
            digits[index]++;
        return digits;
    }
};