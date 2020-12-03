#include <vector>
#include <string>
using namespace std;


//naive
class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen = 0;
        int startindex = 0;
        for(int i = 0; i < s.length(); i++){
            int len = 1;
            int j = i - 1, k = i + 1;
            while(j >= 0 && k < s.length() && s[j--] == s[k++])
                len += 2;
            if(len > maxlen){
                startindex = i - len / 2;
                maxlen = len;
            }

            len = 0;
            j = i, k = i + 1;
            while(j >= 0 && k < s.length() && s[j--] == s[k++])
                len += 2;
            if(len > maxlen){
                startindex = i + 1 - len / 2;
                maxlen = len;
            }
        }
        return s.substr(startindex, maxlen);
    }
};

//Manacher
class Solution {
public:
    string longestPalindrome(string s) {
        string temp(s.length() * 2 + 3, '#');
        temp[0] = '^', temp.back() = '$';
        for(int i = 0; i < s.length(); i++){
            temp[2 * (i + 1)] = s[i];
        }
        vector<int> p(temp.length());
        int rightbound = 1, center = 1;
        int maxlen = 0, startindex = 0;
        for(int i = 2; i < temp.length() - 2; i++){
            int iMirror = 2 * center - i;
            if(i > rightbound || i + p[iMirror] == rightbound){
                if(i + p[iMirror] == rightbound)
                    p[i] = p[iMirror];
                while(temp[i - p[i] - 1] == temp[i + p[i] + 1])
                    p[i]++;
                rightbound = i + p[i];
                center = i;
            }
            else
                p[i] = min(p[iMirror], rightbound - i);
            
            if(p[i] > maxlen){
                //startindex = (i - p[i] + 1) / 2 - 1;
                startindex = (i - p[i]) / 2;
                maxlen = p[i];
            }
        }
        return s.substr(startindex, maxlen);
    }
};