#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int b = 0, e = 0;
        vector<string> C_Str(26);
        unordered_map<string, char> Str_C;

        for(int i = 0; i < pattern.length(); i++){
            while(e < str.length() && str[e] != ' ') e++;

            if(e == b) return false;

            string subs = pattern.substr(b, e - b);

            if(Str_C.find(subs) == Str_C.end())
                Str_C[subs] = pattern[i];
            if(Str_C[subs] != pattern[i]) return false;
            

            if(C_Str[pattern[i] - 'a'] == "")
                C_Str[pattern[i] - 'a'] = subs;
            if(C_Str[pattern[i] - 'a'] != subs) return false;

            b = ++e;
        }

        return b == str.length() + 1;
    }
};