#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.length() > 12 || s.length() < 4) return {};
        string ip;
        vector<string> ret;
        recurse(1, ip, 0, s, ret);
        return ret;
    }

private:
    void recurse(int count, string& ip,int index, string& s, vector<string>& res){
        if(index == s.length()) return;
        if(count == 4){
            if(s.length() - index > 3) return;
            if(s[index] == '0' && s.length() - index > 1) return;
            if(stoi(s.substr(index)) > 255) return;
            ip += s.substr(index);
            res.emplace_back(ip);
            while(ip.back() != '.') ip.pop_back();
        }
        else{
            if(s[index] == '0'){
                ip += "0.";
                recurse(count + 1, ip, index + 1, s, res);
                ip.pop_back();
                ip.pop_back();
            }
            else{
                int num = 0;
                for(int i = index; i < s.length() && i < index + 3; i++){
                    num = num * 10 + s[i] - '0';
                    if(num > 255) break;
                    ip.push_back(s[i]);
                    ip.push_back('.');
                    recurse(count + 1, ip, i + 1, s, res);
                    ip.pop_back();
                }
                while(!ip.empty() && ip.back() != '.') ip.pop_back();
            }
        }
    }
};