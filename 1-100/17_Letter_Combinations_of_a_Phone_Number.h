#include <vector>
#include <string>
using namespace std;


//recurse
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> d = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string path;
        vector<string> res;
        recurse(digits, 0, path, d, res);
        return res;
    }

private:
    void recurse(string& digits, int index, string& path, vector<string>& d, vector<string>& res){
        if(index == digits.length()){
            res.push_back(path);
            return;
        }
        for(char c : d[digits[index] - '0']){
            path.push_back(c);
            recurse(digits, index + 1, path, d, res);
            path.pop_back();
        }
    }
};

//stack
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> d = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<int> indices(digits.size(), 0);
        int len = digits.length();
        vector<string> ret;
        while(true){
            if(indices.size() < len){
                indices.resize(len, 0);
            } 
            string comb(len, ' ');
            for(int i = 0; i < len; i++)
                comb[i] = d[digits[i] - '0'][indices[i]];
            ret.push_back(comb);
            while(!indices.empty() && indices.back() == d[digits[indices.size() - 1] - '0'].length() - 1)
                indices.pop_back();
            if(indices.empty()) break;
            indices.back()++;
        }
        return ret;
    }
};