#include <string>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int i = 0, res = 0;
        while(i < s.length()){
            while(i < s.length() && s[i] == ' ')
                i++;
            
            if(i == s.length()) break;

            while(i < s.length() && s[i] != ' ')
                i++;
            res++;
        }
        return res;
    }
};