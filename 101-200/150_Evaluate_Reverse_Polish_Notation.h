#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto& ele : tokens){
            if(ele == "+" || ele == "-" || ele == "*" || ele == "/")
                eval(s, ele);
            else
                s.push(stoi(ele));
        }
        return s.top();
    }

private:
    void eval(stack<int>& s, string op){
        int num2 = s.top();
        s.pop();
        int num1 = s.top();
        s.pop();
        if(op == "+")
            s.push(num1 + num2);
        else if(op == "-")
            s.push(num1 - num2);
        else if(op == "*")
            s.push(num1 * num2);
        else
            s.push(num1 / num2);
    }
};