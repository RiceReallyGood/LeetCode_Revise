#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> vec1, vec2;
        BigInt2Vec(num1, vec1);
        BigInt2Vec(num2, vec2);
        int sz1 = vec1.size(), sz2 = vec2.size();
        vector<int> res(sz1 + sz2);
        for(int i = 0; i < sz1; i++){
            int carry = 0;
            for(int j = 0; j < sz2; j++){
                int index = i + j;
                res[index] += vec1[i] * vec2[j];
                res[index + 1] += res[i + j] / 10000;
                res[index] %= 10000;
            }
        }
        while(res.size() > 1 && res.back() == 0) res.pop_back();
        string ret = to_string(res.back());
        for(int i = int(res.size()) - 2; i >= 0; i--){
            string part = to_string(res[i]);
            ret += string(4 - part.length(), '0');
            ret += part;
        }
            
        return ret;
    }

private:
    void BigInt2Vec(string& num, vector<int>& vec){
        int len = num.length();
        while(len >= 4){
            vec.push_back(stoi(num.substr(len - 4, 4)));
            len -= 4;
        }
        if(len > 0)
            vec.push_back(stoi(num.substr(0, len)));
    }
};