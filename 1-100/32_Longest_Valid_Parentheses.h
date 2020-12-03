#include <stack>
#include <string>
using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> S;
        S.push(-1);
        int len = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(')
                S.push(i);
            else{
                S.pop();
                if(S.empty())
                    S.push(i);
                else
                    len = max(len, i - S.top());
            }
        }
        return len;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, bound = -1;
        int len = s.length();
        int ret = 0;
        for(int i = 0; i < len ; i++){
            if(s[i] == '(')
                left++;
            else
                right++;
            
            if(left == right)
                ret = max(ret, left + right);
            if(right > left){
                left = right = 0;
                bound = i;
            }
        }

        left = right = 0;
        for(int i = len - 1; i > bound; i--){
            if(s[i] == '(')
                left++;
            else
                right++;
            
            if(left == right)
                ret = max(ret, left + right);
            if(left > right)
                left = right = 0;
        }

        return ret;
    }
};