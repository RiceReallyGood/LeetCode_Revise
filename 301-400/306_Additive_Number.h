#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        vector<string> seq;
        return recurse(num, 0, seq);
    }

private:
    bool recurse(string& num, int index, vector<string>& seq){
        if(index == num.length())
            return seq.size() > 2;

        string part;
        if(seq.size() < 2){
            while(index < num.length()){
                if(part == "0") break;
                part.push_back(num[index++]);
                seq.push_back(part);
                if(recurse(num, index, seq))
                    return true;
                seq.pop_back();
            }
            return false;
        }

        string target = add(seq[seq.size() - 2], seq[seq.size() - 1]);

        for(int i = 0; i < target.length(); i++){
            if(index + i == num.length() || num[index + i] != target[i])
                return false;
        }

        seq.push_back(target);
        if(recurse(num, index + target.length(), seq))
            return true;
        seq.pop_back();
        return false;
    }

    string add(string num1, string num2){
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int carry = 0;
        string ret;
        for(int i = 0; i < num1.length() || i < num2.length(); i++){
            int a = i < num1.length() ? num1[i] - '0' : 0;
            int b = i < num2.length() ? num2[i] - '0' : 0;
            ret.push_back((carry + a + b) % 10 + '0');
            carry = (a + b + carry) / 10;
        }
        if(carry != 0)
            ret.push_back(carry + '0');
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};