#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        int len = 1;
        long range = 26;
        while(n > range){
            n -= range;
            len++;
            range *= 26;
        }
        n--;
        string ret(len, ' ');
        for(int i = 0; i < len; i++){
            ret[len - 1 - i] = n % 26 + 'A';
            n /= 26;
        }
        return ret;
    }
};

class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        while(n){
            ret.push_back((n - 1) % 26 + 'A');
            n = (n - 1) / 26;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};