#include <vector>
#include <string>
#include <stack>
using namespace std;

class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s.empty()) return NestedInteger();
        if(s[0] != '[') return NestedInteger(stoi(s));
        stack<NestedInteger> S;
        NestedInteger ni;
        int index = 1;

        while(index < s.length() - 1){
            if(s[index] == '['){
                S.push(ni);
                ni = NestedInteger();
            }
            else if(s[index] == ']'){
                NestedInteger temp = ni;
                ni = S.top();
                S.pop();
                ni.add(temp);
            }
            else if(s[index] != ','){
                int curr = index;
                while(index < s.length() && s[index] != ',' && s[index] != ']')
                    index++;
                ni.add(NestedInteger(stoi(s.substr(curr, index - curr))));
                index--;
            }
            index++;
        }

        return ni;
    }
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s.empty()) return NestedInteger();
        if(s[0] != '[') return NestedInteger(stoi(s));
        int index = 0;
        return helper(s, index);
    }

private:
    NestedInteger helper(string& s, int& index){
        index++;
        NestedInteger ni;
        while(s[index] != ']'){
            if(s[index] == '[')
                ni.add(helper(s, index));
            else if(s[index] != ','){
                int curr = index;
                while(s[index] != ',' && s[index] != ']') index++;
                ni.add(NestedInteger(stoi(s.substr(curr, index - curr))));
            }
            else
                index++;
        }
        index++;
        return ni;
    }
};