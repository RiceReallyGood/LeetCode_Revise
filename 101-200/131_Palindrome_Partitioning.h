#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        if(s.empty()) return {};
        vector<vector<string>> ret;
        ret.push_back({s.substr(0, 1)});
        for(int index = 1; index < s.length(); index++){
            int pnum = ret.size();
            for(int i = 0; i < pnum; i++){
                int psz = ret[i].size();
                if(ret[i][psz - 1] == s.substr(index, 1)){
                    vector<string> temp = ret[i];
                    temp.pop_back();
                    temp.push_back(string(2, s[index]));
                    ret.push_back(temp);
                }
                if(psz > 1 && ret[i][psz - 2] == s.substr(index, 1)){
                    vector<string> temp = ret[i];
                    string backstring;
                    backstring.push_back(s[index]);
                    backstring += ret[i][psz - 1];
                    backstring.push_back(s[index]);
                    temp.pop_back(), temp.pop_back();
                    temp.push_back(backstring);
                    ret.push_back(temp);
                }
                ret[i].push_back(s.substr(index, 1));
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<string>> partition(string s) {
        if(s.empty()) return {};
        vector<vector<string>> ret;
        vector<int> p = Manacher(s);
        vector<string> partitions;
        backtrace(0, s, p, partitions, ret);
        return ret;
    }

private:
    vector<int> Manacher(string& s){
        string new_s = "^#";
        for(char c : s){
            new_s.push_back(c);
            new_s.push_back('#');
        }
        new_s.push_back('$');
        int len = s.length();
        vector<int> p(2 * len + 3);
        int center = 1, rightbound = 1;
        for(int i = 2; i < p.size() - 2; i++){
            int iMirror = 2 * center - i;
            if(i > rightbound || i + p[iMirror] == rightbound){
                if(i <= rightbound) p[i] = p[iMirror];
                while(new_s[i - p[i] - 1] == new_s[i + p[i] + 1])
                    ++p[i];
                center = i;
                rightbound = i + p[i];
            }
            else
                p[i] = min(rightbound - i, p[iMirror]);
        }
        return p;
    }

    void backtrace(int index, string& s, vector<int>& p, vector<string>& partitions, vector<vector<string>>& res){
        if(index == s.length()){
            res.emplace_back(partitions);
            return;
        }

        for(int r = index; r < s.length(); r++){
            if(p[index + r + 2] >= r - index + 1){ //s.substr(index, r - index + 1) is Palindrome
                partitions.push_back(s.substr(index, r - index + 1));
                backtrace(r + 1, s, p, partitions, res);
                partitions.pop_back();
            }
        }
    }
};