#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int x = 1, y = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'A') OpA(x, y);
            else OpB(x, y);
        }
        return x + y;
    }

private:
    void OpA(int& x, int& y){
        x = 2 * x + y;
    }

    void OpB(int& x, int& y){
        y = 2 * y + x;
    }
};