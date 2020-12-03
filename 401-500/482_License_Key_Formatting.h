#include <string>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int keyc = 0;
        for(char c : S){
            if(c != '-') keyc++;
        }

        int index = 0, count = keyc % K;
        string res;

        while(keyc > 0){
            if(count == 0){
                count = K;
                if(!res.empty())
                    res.push_back('-');
            }

            if(S[index] != '-'){
                res.push_back(toupper(S[index]));
                count--;
                keyc--;
            }

            index++;
        }

        return res;
    }
};