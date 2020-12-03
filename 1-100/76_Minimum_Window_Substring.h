#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int cint[128] = {0};
        for(char c : t) cint[c]++;
        int pos = 0, len = s.length() + 1;
        int cins[128] = {0}, count = 0;
        int i = 0, j = 0;
        while(j < s.length()){
            while(j < s.length() && count < t.length()){
               if(cins[s[j]] < cint[s[j]]) count++;
               cins[s[j]]++;
               j++;
            }
            while(count >= t.length()){
                if(cins[s[i]] == cint[s[i]]){
                    count--;
                    if(j - i < len){
                        pos = i;
                        len = j - i;
                    }
                }
                cins[s[i]]--;
                i++;
            }
        }
        if(len == s.length() + 1) return "";
        return s.substr(pos, len);
    }
};