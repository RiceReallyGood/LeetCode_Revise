#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{')
                S.push(c);
            else if(c == ')'){
                if(S.empty() || S.top() != '(')
                    return false;
                S.pop();
            }
            else if(c == ']'){
                if(S.empty() || S.top() != '[')
                    return false;
                S.pop();
            }
            else{
                if(S.empty() || S.top() != '{')
                    return false;
                S.pop();
            }
        }
        return S.empty();
    }
};