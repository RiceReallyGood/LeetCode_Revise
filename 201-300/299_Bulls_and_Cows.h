#include <string>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int counts[10] = { 0 };
        int countg[10] = { 0 };
        int Bulls = 0, Cows = 0;

        for(int i = 0; i < secret.length(); i++){
            if(secret[i] == guess[i]){
                Bulls++;
            }
            else{
                counts[secret[i] - '0']++;
                countg[guess[i] - '0']++;
            }
        }
        for(int i = 0; i < 10; i++) Cows += min(counts[i], countg[i]);

        return to_string(Bulls) + "A" + to_string(Cows) + "B";
    }
};