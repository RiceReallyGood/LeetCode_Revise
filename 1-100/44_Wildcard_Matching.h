#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length(), plen = p.length();
        vector<vector<bool>> match(slen + 1, vector<bool>(plen + 1, false));
        match[0][0] = true;
        for(int j = 1; j <= plen; j++){
            if(p[j - 1] == '*' && match[0][j - 1])
                match[0][j] = true;
        }

        for(int i = 1; i <= slen; i++){
            for(int j = 1; j <= plen; j++){
                if(p[j - 1] == '*')
                    match[i][j] = match[i][j - 1] || match[i - 1][j];
                else if(p[j - 1] == '?' || p[j - 1] == s[i - 1])
                    match[i][j] = match[i - 1][j - 1];
            }
        }
        return match[slen][plen];
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length(), plen = p.length();
        vector<vector<bool>> match(plen + 1, vector<bool>(slen + 1, false));
        match[0][0] = true;
        for(int i = 1; i <= plen; i++){
            match[i][0] = (p[i - 1] == '*' && match[i - 1][0]);
            if(p[i - 1] == '*'){
                for(int j = 1; j <= slen; j++)
                    match[i][j] = match[i][j - 1] || match[i - 1][j];
            }
            else if(p[i - 1] == '?'){
                for(int j = 1; j <= slen; j++)
                    match[i][j] = match[i - 1][j - 1];
            }
            else{
                for(int j = 1; j <= slen; j++){
                    match[i][j] = (p[i - 1] == s[j - 1]) && match[i - 1][j - 1];
                }
            }
        }
        return match[plen][slen];
    }
};

class Solution {
    public:
	bool isMatch(string s, string p) {
		int sIdx = 0, pIdx = 0;
        int sTemp = -1, pStar = -1;
        int slen = s.length(), plen = p.length();
        while(sIdx < slen){
            if(pIdx < plen && p[pIdx] == '*'){
                pStar = pIdx;
                sTemp = sIdx;
                pIdx++;
            }
            else if(pIdx < plen && (p[pIdx] == '?' || p[pIdx] == s[sIdx])){
                pIdx++;
                sIdx++;
            }
            else if(pStar == -1){
                return false;
            }
            else{
                pIdx = pStar + 1;
                sTemp++;
                sIdx = sTemp;
            }
        }
        while(pIdx < plen){
            if(p[pIdx++] != '*')
                return false;
        }
        return true;
	}
};