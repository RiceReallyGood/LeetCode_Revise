#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//KMP Algorithm
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return s;
        string revs = s;
        reverse(revs.begin(), revs.end());
        string p = s + "#" + revs;
        int n = p.length();
        vector<int> prefixlen(n, 0);

        for (int i = 1, j = 0; i < n; i++) {
            while (j != 0 && p[j] != p[i])
                j = prefixlen[j - 1];

            if (p[j] == p[i]) j++;
            prefixlen[i] = j;
        }

        return revs + s.substr(prefixlen[n - 1]);
    }
};

//KMP2
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        vector<int> prefixlen(n, 0);

        for (int i = 1, j = 0; i < n; i++) {
            while (j != 0 && s[j] != s[i])
                j = prefixlen[j - 1];

            if (s[i] == s[j]) j++;
            prefixlen[i] = j;
        }

        int maxlen = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (maxlen != 0 && s[maxlen] != s[i])
                maxlen = prefixlen[maxlen - 1];

            if (s[i] == s[maxlen]) maxlen++;
        }

        string add = s.substr(maxlen);
        reverse(add.begin(), add.end());
        return add + s;
    }
};

//Manacher Algirithm
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return s;
        int n = s.length();
        string new_s(2 * n + 3, '#');
        for (int i = 0; i < n; i++)
            new_s[2 * (i + 1)] = s[i];
        new_s[0] = '^', new_s[2 * n + 2] = '$';
        vector<int> p(new_s.length());

        int center = 1, rightbound = 1;
        for (int i = 2; i < new_s.length() - 1; i++) {
            int iMirror = 2 * center - i;
            if (i > rightbound || i + p[iMirror] == rightbound) {
                if (i <= rightbound) p[i] = p[iMirror];
                while (new_s[i + p[i] + 1] == new_s[i - p[i] - 1])
                    p[i]++;
                center = i;
                rightbound = i + p[i];
            } else
                p[i] = min(p[iMirror], rightbound - i);
        }

        int maxlen = n;
        while (p[maxlen + 1] != maxlen) maxlen--;

        string ret = s.substr(maxlen);
        reverse(ret.begin(), ret.end());
        ret += s;
        return ret;
    }
};