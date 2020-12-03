#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        strip(s);
        reverse(s.begin(), s.end());
        int len = s.length();
        int i = 0, j = 0;
        while(i < len){
            while(j < len && s[j] != ' ') j++;
            reverse(s.begin() + i, s.begin() + j);
            while(j < len && s[j] == ' ') j++;
            i = j;
        }
        return s;
    }

private:
    void strip(string& s){
        while(!s.empty() && s.back() == ' ')
            s.pop_back();
        int len = s.length();
        int index = 0, i = 0;
        while(i < len && s[i] == ' ') i++;
        while(i < len){
            while(i < len && s[i] != ' ')
                s[index++] == s[i++];
            if(i < len) s[index++] = ' ';
            while(i < len && s[i] == ' ')
                i++;
        }
    }
};