#include <streambuf>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0};
        int letters = ransomNote.length();
        for(int i = 0; i < ransomNote.length(); i++)
            count[ransomNote[i] - 'a']++;

        for(int i = 0; i < magazine.size(); i++){
            if(count[magazine[i] - 'a'] > 0){
                letters--;
                count[magazine[i] - 'a']--;
            }
            if(letters == 0) return true;
        }

        return false;
    }
};