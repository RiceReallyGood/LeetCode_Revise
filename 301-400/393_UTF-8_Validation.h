#include <vector>
using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int index = 0;
        int mask1 = 0x80, mask2 = 0xC0;
        while(index < data.size()){
            if((data[index] & mask2) == mask1)
                return false;
            if((data[index] & mask1) == 0){
                index++;
                continue;
            }

            int temp = data[index], len = 0;
            while((temp & mask1) != 0){
                len++;
                temp <<= 1;
            }
            if(len > 4) return false;

            for(int i = 1; i < len; i++){
                if(index + i == data.size() || (data[index + i] & mask2) != mask1)
                    return false;
            }
            index += len;
        }
        return true;
    }
};