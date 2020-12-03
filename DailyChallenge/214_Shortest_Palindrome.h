#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        vector<int> prefixlen(n, 0);

        for (int i = 1, j = 0; i < n; i++) {
            while (j != 0 && s[j] != s[i])
                j = prefixlen[j - 1];

            if (s[i] == s[j]) j++;
            prefixlen[i] = j;
        }

        int maxlen = 0;
        for(int i = n - 1; i >= 0; i--){
            while(maxlen != 0 && s[maxlen] != s[i])
                maxlen = prefixlen[maxlen - 1];
            
            if(s[i] == s[maxlen]) maxlen++;
        }

        string add = s.substr(maxlen);
        reverse(add.begin(), add.end());
        return add + s;
    }
};