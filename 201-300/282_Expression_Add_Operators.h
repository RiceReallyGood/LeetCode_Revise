#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        if(num.empty()) return {};
        this->target = target;
        string exp;
        exp.push_back(num[0]);
        vector<string> res;
        recurse(num, 1, num[0] - '0', num[0] - '0', num[0] - '0', exp, res);
        return res;
    }

private:
    int target;
    void recurse(string& num, int index, int res, int prevele, int prevpart, string& exp, vector<string>& exps){
        if(index == num.length()){
            if(res == this->target && exp.length() != num.length())
                exps.push_back(exp);
            return;
        }

        long currele, currpart;
        // +
        exp.push_back('+');
        exp.push_back(num[index]);
        currele = num[index] - '0';
        currpart = num[index] - '0';
        recurse(num, index + 1, res + currpart, currele, currpart, exp, exps);
        // - 
        exp[exp.length() - 2] = '-';
        currpart = -(num[index] - '0');
        recurse(num, index + 1, res + currpart, currele, currpart, exp, exps);
        // *
        exp[exp.length() - 2] = '*';
        currpart = prevpart * currele;
        if(currpart >= INT_MIN && currpart <= INT_MAX)
            recurse(num, index + 1, res - prevpart + currpart, currele, currpart, exp, exps);

        exp.pop_back();
        exp.pop_back();

        if(prevele != 0){
            currele = prevele * 10 + (num[index] - '0');
            currpart = prevpart / prevele * currele;
            if(currpart >= INT_MIN & currpart <= INT_MAX){
                exp.push_back(num[index]);
                recurse(num, index + 1, res - prevpart + currele, currele, currpart, exp, exps);
                exp.pop_back();
            }
        }
    }
};