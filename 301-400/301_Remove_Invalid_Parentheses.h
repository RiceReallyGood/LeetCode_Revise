#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        //preprocess
        while(!s.empty() && s.back() == '(') s.pop_back();
        reverse(s.begin(), s.end());
        while(!s.empty() && s.back() == ')') s.pop_back();
        reverse(s.begin(), s.end());

        int redundantl = 0, redundantr = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                redundantl++;
            }
            else if(s[i] == ')'){
                if(redundantl > 0) redundantl--;
                else redundantr++;
            }
        }

        string candidate;
        vector<string> res;
        recurse(s, 0, 0, 0, redundantl, redundantr, false, candidate, res);
        return res;
    }

private:

    void recurse(string& s, int index, int l, int r, int redundantl, int redundantr, bool prevused, string& candidate, vector<string>& res){
        if(redundantl < 0 || redundantr < 0) return;
        if(s.length() - index < redundantl + redundantr) return;
        if(index == s.length()){
            res.push_back(candidate);
            return;
        }

        if(s[index] == '('){
            recurse(s, index + 1, l, r, redundantl - 1, redundantr, false, candidate, res);
            if(index == 0 || s[index - 1] != s[index] || prevused){
                candidate.push_back('(');
                recurse(s, index + 1, l + 1, r, redundantl, redundantr, true, candidate, res);
                candidate.pop_back();
            }
        }
        else if(s[index] == ')'){
            recurse(s, index + 1, l , r, redundantl, redundantr - 1, false, candidate, res);
            if(r < l && (s[index - 1] != s[index] || prevused)){
                candidate.push_back(')');
                recurse(s, index + 1, l, r + 1, redundantl, redundantr, true, candidate, res);
                candidate.pop_back();
            }
        }
        else{
            candidate.push_back(s[index]);
            recurse(s, index + 1, l, r, redundantl, redundantr, true, candidate, res);
            candidate.pop_back();
        }
    }
};