#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s(2 * n, ' ');
        vector<string> res;
        recurse(s, 0, n, 0, res);
        return res;
    }

private:
    void recurse(string& s, int index, int n, int left, vector<string>& res){
        if(index == 2 * n){
            res.push_back(s);
            return;
        }

        if(left < n){
            s[index] = '(';
            recurse(s, index + 1, n, left + 1, res);
        }

        if(index - left < left){
            s[index] = ')';
            recurse(s, index + 1, n, left, res);
        }
    }
};