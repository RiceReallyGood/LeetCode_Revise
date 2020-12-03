#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.length();
    }
};

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        vector<int> prefix(len);

        for(int i = 1, j = 0; i < len; i++){
            while(j != 0 && s[i] != s[j])
                j = prefix[j - 1];
            
            if(s[i] == s[j]) j++;
            prefix[i] = j;
        }

        return prefix[len - 1] != 0 && len % (len - prefix[len - 1]) == 0;
    }
};