#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        counts.resize(10);
        for(int i = 1; i < 10; i++)
            counts[i] = 10 * counts[i - 1] + 1;
        
        int temp = n;
        digits.clear();
        while(temp){
            digits.push_back(temp % 10);
            temp /= 10;
        }
        reverse(digits.begin(), digits.end());
        return KthNumberIn(0, digits.size(), k, n);
    }

private:
    vector<int> digits;
    vector<int> counts;
    int KthNumberEx(int start, int len, int k){
        //Not include n
        if(k == 0) return start;
        int digit = (k - 1) / counts[len];
        return KthNumberEx(start * 10 + digit, len - 1, k - digit * counts[len] - 1);
    }

    int KthNumberIn(int start, int len, int k, int n){
        //include n
        if(k == 0) return start;
        int i = digits.size() - len;
        int leftbound = (digits[i] - (i == 0)) * counts[len] + 1;
        int rightbound = n - (9 - digits[i]) * counts[len - 1];

        if(k < leftbound){
            int digit = (k - 1) / counts[len];
            return KthNumberEx(start * 10 + digit + (i == 0), len - 1, k - digit * counts[len] - 1);
        }
        else if(k > rightbound){
            int digit = (k - rightbound - 1) / counts[len - 1] + digits[i] + 1;
            return KthNumberEx(start * 10 + digit, len - 2, k - rightbound - (digit - digits[i] - 1) * counts[len - 1] - 1);
        }
        else{
            return KthNumberIn(start * 10 + digits[i], len - 1, k - leftbound, rightbound - leftbound);
        }
    }
};

class Solution {
public:
    int findKthNumber(int n, int k) {
        int prefix = 1;
        k--;
        while(k > 0){
            int step = getStep(prefix, n);
            if(k < step){
                prefix *= 10;
                k--;
            }
            else{
                prefix++;
                k -= step;
            }
        }
        return prefix;
    }

private:
    int getStep(int prefix, int n){
        long long curr = prefix, next = curr + 1;
        int step = 0;
        while(curr <= n){
            step += std::min<long>(next, n + 1) - curr;
            next *= 10;
            curr *= 10;
        }
        return step;
    }
};