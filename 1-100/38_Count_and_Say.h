#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        int index = 1;
        string ret = "1";
        for(int index = 1; index < n; index++){
            string temp;
            int count = 1;
            char c = ret[0];
            for(int i = 1; i < ret.length(); i++){
                if(ret[i] != ret[i - 1]){
                    temp += to_string(count);
                    temp.push_back(c);
                    count = 1;
                    c = ret[i];
                }
                else{
                    count++;
                }
            }
            temp += to_string(count);
            temp.push_back(c);
            swap(ret, temp);
        }
        return ret;
    }
};