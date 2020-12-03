#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string smallestGoodBase(string n) {
        //find len
        ll mask = 1;
        ll num = stol(n);
        int len = 1;
        while(mask < num){
            mask = (mask << 1) + 1;
            len++;
        }

        for(int l = len; l >= 1; l--){
            ll base = findbase(num, l);
            if(base!= -1) return to_string(base);
        }
        return "-1";
    }

private:
    using ll = long long;

    ll findbase(ll num, int len){
        ll l = 2, r = num - 1;

        while(l <= r){
            ll c = l + (r - l) / 2;
            ll dec = todec(c, len);

            if(dec == num) return c;
            if(dec < num) l = c + 1;
            else r = c - 1;
        }
        return -1;
    }

    ll todec(ll base, int len){
        ll res = 1;
        for(int i = 1; i < len; i++){
            if((LONG_LONG_MAX - 1) / base < res)
                return LONG_LONG_MAX;
            res = res * base + 1;
        }
        return res;
    }
};