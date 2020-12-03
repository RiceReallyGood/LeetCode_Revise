#include <string>
using namespace std;

class Solution {
public:
    bool patternMatching(string pattern, string value) {
        if(pattern.empty()) return value.empty();
        int na = 0, nb = 0;
        for(char c : pattern){
            if(c == 'a') na++;
            else nb++;
        }
        int vlen = value.length();
        if(na == 0){
            if(vlen % nb != 0) return false;
            int blen = vlen / nb;
            string sb = value.substr(0, blen);
            for(int i = blen; i < vlen; i += blen)
                if(value.substr(i, blen) != sb)
                    return false;
            return true;
        }
        if(nb == 0){
            if(vlen % na != 0) return false;
            int alen = vlen / na;
            string sa = value.substr(0, alen);
            for(int i = alen; i < vlen; i += alen)
                if(value.substr(i, alen) != sa)
                    return false;
            return true;
        }
        if(value.empty()) return false;
        int alen = 0, blen;
        while(na * alen <= vlen){
            if((vlen - na * alen) % nb != 0){
                alen++;
                continue;
            }
            blen = (vlen - na * alen) / nb;
            string sa, sb;
            bool seta = false, setb = false;
            int index = 0, i = 0;
            while(index < vlen){
                if(pattern[i] == 'a'){
                    if(!seta){
                        sa = value.substr(index, alen);
                        seta = true;
                        if(setb && sa == sb) break;
                    }
                    else if(value.substr(index, alen) != sa)
                        break;
                    i++;
                    index += alen;
                }
                else{
                    if(!setb){
                        sb = value.substr(index, blen);
                        setb = true;
                        if(seta && sa == sb) break;
                    }
                    else if(value.substr(index, blen) != sb)
                        break;
                    i++;
                    index += blen;
                }
            }
            if(index == vlen) return true;
            alen++;
        }
        return false;
    }
};