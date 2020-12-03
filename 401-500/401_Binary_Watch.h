#include <vector>
#include <streambuf>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        backtrace(0, 0, num, res);
        return res;
    }

private:
    void backtrace(int state, int index, int on, vector<string>& res){
        if(index == 10){
            int h = state / 64, m = state % 64;
            if(h >= 12 || m >= 60) return;
            string t = to_string(h) + ":";
            if(m < 10) t += "0" + to_string(m);
            else t += to_string(m);
            res.push_back(t);
        }

        if(10 - index > on)
            backtrace(state, index + 1, on, res); 
        
        if(on > 0){
            state = state | (1 << (9 - index));
            backtrace(state, index - 1, on - 1, res);
            state = state ^ (1 << (9 - index));
        }  
    }
};