#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int index = 0, currlen = -1;
        int maxlen = 0;
        vector<int> parts;
        while(index < input.length()){
            int tcount = 0;
            while(input[index + tcount] == '\t') tcount++;
            index += tcount;
            int namelen = 0;
            bool isfile = false;
            while(index + namelen < input.length() && input[index + namelen] != '\n'){
                if(input[index + namelen] == '.') isfile = true;
                namelen++;
            }
            index += namelen + 1;
            
            while(parts.size() > tcount){
                currlen -= parts.back();
                parts.pop_back();
            }

            currlen += namelen + 1;
            parts.push_back(namelen + 1);
            if(isfile)
                maxlen = max(maxlen, currlen);
        }

        return maxlen;
    }
};