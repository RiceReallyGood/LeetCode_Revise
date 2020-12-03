#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<char> ops;
        stack<int> nums;
        int index = 0;
        while(index < s.length()){
            if(s[index] == ' '){
                index++;
                continue;
            }
            if(s[index] == '+' || s[index] == '-' || s[index] == '(')
                ops.push(s[index++]);
            else if(s[index] == ')'){
                nums.push(eval(nums, ops));
                index++;
            }
            else{
                int num = 0;
                while(index < s.length() && isdigit(s[index]))
                    num = num * 10 + s[index++] - '0';
                nums.push(num);
            }
        }
        return eval(nums, ops);
    }

private:
    int eval(stack<int>& nums, stack<char>& ops){
        stack<int> n;
        stack<char> o;
        while(!ops.empty() && ops.top() != '('){
            n.push(nums.top());
            o.push(ops.top());
            nums.pop();
            ops.pop();
        }
        int ret = nums.top();
        nums.pop();
        if(!ops.empty()) ops.pop();

        while(!o.empty()){
            if(o.top() == '+')
                ret += n.top();
            else
                ret -= n.top();
            o.pop();
            n.pop();
        }
        return ret;
    }
};