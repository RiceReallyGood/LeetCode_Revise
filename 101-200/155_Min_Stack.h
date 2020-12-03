#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        eles.push(x);
        if(mins.empty())
            mins.push(x);
        else
            mins.push(min(mins.top(), x));
    }
    
    void pop() {
        eles.pop();
        mins.pop();
    }
    
    int top() { return eles.top(); }
    
    int getMin() { return mins.top(); }

private:
    stack<int> eles;
    stack<int> mins;
};