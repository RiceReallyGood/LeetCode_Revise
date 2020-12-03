#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int priority[128] = {};
        priority['+'] = priority['-'] = 1;
        priority['*'] = priority['/'] = 2;
        stack<int> nums;
        stack<char> ops;
        int index = 0;

        while(index < s.length()){
            if(s[index] == ' '){
                index++;
                continue;
            }

            if(s[index] == '(')
                ops.push(s[index++]);
            else if(s[index] == ')'){
                while(ops.top() != '('){
                    eval(nums, ops.top());
                    ops.pop();
                }
                ops.pop();
                index++;
            }
            else if(s[index] == '+' || s[index] == '-' || s[index] == '*' || s[index] == '/'){
                while(!ops.empty() && priority[ops.top()] >= priority[s[index]]){
                    eval(nums, ops.top());
                    ops.pop();
                }
                ops.push(s[index++]);
            }
            else{
                int num = 0;
                while(index < s.length() && isdigit(s[index]))
                    num = num * 10 + (s[index++] - '0');
                nums.push(num);
            }
        }

        while(!ops.empty()){
            eval(nums, ops.top());
            ops.pop();
        }
        return nums.top();
    }

private:
    void eval(stack<int>& nums, char op){
        int num2 = nums.top(); nums.pop();
        int num1 = nums.top(); nums.pop();
        if(op == '+') nums.push(num1 + num2);
        else if(op == '-') nums.push(num1 - num2);
        else if(op == '*') nums.push(num1 * num2);
        else if(op == '/') nums.push(num1 / num2);
    }
};