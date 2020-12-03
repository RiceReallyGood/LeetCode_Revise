#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string ret;
        stack<int> count, beg;

        int index = 0;
        while(index < s.length()){
            if(isdigit(s[index])){
                int n = 0;
                while(isdigit(s[index]))
                    n = n * 10 + (s[index++] - '0');
                count.push(n);
                beg.push(ret.length());
            }
            else if(s[index] == ']'){
                int n = count.top();
                count.pop();
                int b = beg.top();
                beg.pop();
                string subs = ret.substr(b);
                for(int i = 1; i < n; i++){
                    ret += subs;
                }
            }
            else
                ret.push_back(s[index]);
            index++;
        }
        return ret;
    }
};