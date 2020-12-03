#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sid = 0, tid = 0;
        while(sid < s.length() && tid < t.length()){
            if(s[sid] == t[tid]) sid++;
            tid++;
        }
        return sid == s.length();
    }
};