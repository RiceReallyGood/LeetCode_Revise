// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while(l < r){
            int c = l + (r - l) / 2;
            if(isBadVersion(c))
                r = c;
            else
                l = c + 1;
        }
        return l;
    }
};