#include <string>
using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        int charcount[26] = {0};
        for(char c : s) charcount[c - 'a']++;
        int digitscount[10] = {0};

        //zero
        digitscount[0] = charcount['z' - 'a'];
        sub(charcount, "zero", digitscount[0]);

        //two
        digitscount[2] = charcount['w' - 'a'];
        sub(charcount, "two", digitscount[2]);

        //four
        digitscount[4] = charcount['u' - 'a'];
        sub(charcount, "four", digitscount[4]);

        //one
        digitscount[1] = charcount['o' - 'a'];
        sub(charcount, "one", digitscount[1]);

        //three
        digitscount[3] = charcount['r' - 'a'];
        sub(charcount, "three", digitscount[3]);

        //five
        digitscount[5] = charcount['f' - 'a'];
        sub(charcount, "five", digitscount[5]);

        //six
        digitscount[6] = charcount['x' - 'a'];
        sub(charcount, "six", digitscount[6]);

        //seven
        digitscount[7] = charcount['s' - 'a'];
        sub(charcount, "seven", digitscount[7]);

        //eight
        digitscount[8] = charcount['g' - 'a'];
        sub(charcount, "eight", digitscount[8]);

        //nine
        digitscount[9] = charcount['i' -'a'];
        sub(charcount, "nine", digitscount[9]);

        string ret;
        for(int i = 0; i < 10; i++){
            ret += string(digitscount[i], '0' + i);
        }
        return ret;
    }

private:
    void sub(int charcount[], const string& word, int count){
        for(char c : word)  charcount[c - 'a'] -= count;
    }
};