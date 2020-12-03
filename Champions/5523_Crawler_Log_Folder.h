#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int pos = 0;
        for(int i = 0; i < logs.size(); i++){
            if(logs[i] == "../")
                pos = pos == 0 ? 0 : pos - 1;
            else if(logs[i] != "./")
                pos++;
        }
        return pos;
    }
};