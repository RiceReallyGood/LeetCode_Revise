#include <string>
using namespace std;

class Solution {
public:
    int strongPasswordChecker(string s) {
        if(s.length() < 4) return 6 - s.length();
        bool low = false, up = false, digit = false;

        for(int i = 0; i < s.length(); i++){
            if(!low && (s[i] >= 'a' && s[i] <= 'z')) low = true;
            if(!up && (s[i] >= 'A' && s[i] <= 'Z')) up = true;
            if(!digit && (s[i] >= '0' && s[i] <= '9')) digit = true;
        }

        int lack = 0;
        if(!low) lack++;
        if(!up) lack++;
        if(!digit) lack++;
    }
};