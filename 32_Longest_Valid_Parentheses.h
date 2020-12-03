#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> index;
        index.push(-1);
        int maxlen = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') index.push(i);
            else{
                index.pop();
                if(index.empty()) index.push(i);
                else maxlen = max(maxlen, i - index.top());
            }
        }
        return maxlen;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0;
        int maxlen = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                left++;
            else{
                right++;
                if(right > left)
                    left = right = 0;
                else if(left == right)
                    maxlen = max(maxlen, left + right);
            }
        }

        left = right = 0;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == ')')
                right++;
            else{
                left++;
                if(left > right)
                    left = right = 0;
                else if(left == right)
                    maxlen = max(maxlen, left + right);
            }
        }

        return maxlen;
    }
};