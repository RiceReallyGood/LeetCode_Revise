#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> words;
        return recurse(s, 0, words);
    }

private:
    int recurse(const string& s, int index, unordered_set<string>& words){
        if(index == s.length()) return words.size();

        int res = 0;
        for(int j = index; j < s.length(); j++){
            if(words.find(s.substr(index, j - index + 1)) == words.end()){
                words.insert(s.substr(index, j - index + 1));
                res = max(res, recurse(s, j + 1, words));
                words.erase(s.substr(index, j - index + 1));
            }
        }
        return res;
    }
};