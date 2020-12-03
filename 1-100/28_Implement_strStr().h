#include <string>
#include <vector>
using namespace std;

//KMP Algorithm
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        vector<int> prefix(needle.size());

        //preprocess
        for(int i = 1, j = 0; i < needle.size(); i++){
            while(j != 0 && needle[i] != needle[j])
                j = prefix[j - 1];
            if(needle[i] == needle[j]) j++;
            prefix[i] = j;
        }

        for(int i = 0, j = 0; i < haystack.size(); i++){
            while(j != 0 && haystack[i] != needle[j])
                j = prefix[j - 1];
            if(haystack[i] == needle[j]) j++;
            if(j == needle.size())
                return i + 1 - j;
        }
        return -1;
    }
};