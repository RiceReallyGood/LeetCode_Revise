#include <string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for(int i = 1; i <= n; i++)
            s.push_back(i + '0');
        k--;
        int prod = 1;
        for(int i = 1; i <= n; i++) prod *= i;

        for(int it = 0; it < n; it++){
            prod /= n - it;
            int index = k / prod;
            char c = s[index];
            for(int i = index + 1; i < n; i++)
                s[i - 1] = s[i];
            s[n - 1] = c;
            k %= prod;
        }
        return s;
    }
};