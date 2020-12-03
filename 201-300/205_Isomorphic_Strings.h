#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        char m[128] = {0};
        bool used[128] = {false};
        for(int i = 0; i < s.length(); i++){
            if(m[s[i]] != 0){
                if(m[s[i]] != t[i])
                    return false;
            }
            else{
                if(used[t[i]]) return false;
                m[s[i]] = t[i];
                used[t[i]] = true;
            }
        }
        return true;
    }
};


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int prev_s[128] = {};
        int prev_t[128] = {};
        for(int i = 0; i < s.length(); i++){
            if(prev_s[s[i]] != prev_t[t[i]])
                return false;
            prev_s[s[i]] = i + 1;
            prev_t[t[i]] = i + 1;
        }
        return true;
    }
};