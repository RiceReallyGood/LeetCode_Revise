#include <string>
using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        int i = 0, spaces = 0, words = 0;
        while(i < text.length()){
            while(i < text.length() && text[i] == ' '){
                i++;
                spaces++;
            }
            if(i < text.length()) words++;

            while(i < text.length() && text[i] != ' ')
                i++;
        }
        int interspace = words == 1 ? 0 : spaces / (words - 1);
        i = 0;
        string res;
        while(i < text.length()){
            while(i < text.length() && text[i] == ' '){
                i++;
            }
            while(i < text.length() && text[i] != ' ')
                res.push_back(text[i++]);
            
            if(--words == 0) break;
            
            res += string(interspace, ' ');
        }

        while(res.length() < text.length())
            res.push_back(' ');
        
        return res;
    }
};