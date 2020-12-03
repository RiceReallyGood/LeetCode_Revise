#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.empty()) return 0;
        int n = words.size();
        vector<int> bitform(n, 0);
        for(int i = 0; i < words.size(); i++){
            for(char c : words[i]){
                bitform[i] |= 1 << (c - 'a');
            }
        }

        int maxprod = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if((bitform[i] & bitform[j]) != 0){
                    maxprod = max(maxprod, int(words[i].length() * words[j].length()));
                }
            }
        }
        return maxprod;
    }
};