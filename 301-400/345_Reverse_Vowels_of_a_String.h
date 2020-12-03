#include <string>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        if(s.empty()) return "";
        bool isVowel[128] = {false};
        isVowel['a'] = true, isVowel['e'] = true, isVowel['i'] = true, isVowel['o'] = true, isVowel['u'] = true;
        isVowel['A'] = true, isVowel['E'] = true, isVowel['I'] = true, isVowel['O'] = true, isVowel['U'] = true;
        int i = 0, j = s.length() - 1;
        while(i < j){
            while(i < j && !isVowel[s[i]]) i++;
            while(i < j && !isVowel[s[j]]) j--;
            swap(s[i++], s[j--]);
        }
        return s;
    }
};