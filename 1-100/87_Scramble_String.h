#include <string>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        if(s1 == s2) return true;
        return recurse(s1, 0, s1.length(), s2, 0, s2.length());
    }

private:
    bool ispermutation(string& s1, int b1, int e1, string& s2, int b2, int e2){
        int count[128] = {0};
        for(int i = b1; i < e1; i++) count[s1[i]]++;
        for(int i = b2; i < e2; i++){
            if(count[s2[i]] == 0) return false;
            else count[s2[i]]--;
        }   
        return true;
    }

    bool recurse(string& s1, int b1, int e1, string& s2, int b2, int e2){
        if(!ispermutation(s1, b1, e1, s2, b2, e2)) return false;
        int len = e1 - b1;
        if(len <= 2) return true;
        for(int i = 1; i < len; i++){
            if(recurse(s1, b1, b1 + i, s2, b2, b2 + i) &&
               recurse(s1, b1 + i, e1, s2, b2 + i, e2))
                return true;
            if(recurse(s1, b1, b1 + i, s2, e2 - i, e2) &&
               recurse(s1, b1 + i, e1, s2, b2, e2 - i))
                return true;
        }
        return false;
    }
};