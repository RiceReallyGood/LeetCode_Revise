#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastindex(26, -1);
        vector<bool> used(26, false);
        for(int i = 0; i < s.length(); i++) lastindex[s[i] - 'a'] = i;

        string ret;
        for(int i = 0; i < s.length(); i++){
            if(used[s[i] - 'a']) continue;
            while(!ret.empty() && s[i] < ret.back() && lastindex[ret.back() - 'a'] > i){
                ret.pop_back();
                used[s[i] - 'a']= false;
            }
            ret.push_back(s[i]);
            used[s[i] - 'a'] = true;
        }
        return ret;
    }
};