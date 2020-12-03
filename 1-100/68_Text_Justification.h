#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int index = 0, count = 0, chs = 0;
        vector<string> ret;
        while(index < words.size()){
            if(count + chs + words[index].length() <= maxWidth){
                count++;
                chs += words[index++].length();
            }
            else{
                if(count == 1){
                    ret.push_back(words[index - 1]);
                    ret.back().resize(maxWidth, ' ');
                }
                else{
                    int avrg = (maxWidth - chs) / (count - 1);
                    int left = (maxWidth - chs) % (count - 1);
                    string line;
                    for(int i = 0; i < count - 1; i++){
                        line += words[index - count + i];
                        if(i < left)
                            line += string(avrg + 1, ' ');
                        else
                            line += string(avrg, ' ');
                    }
                    line += words[index - 1];
                    ret.push_back(line);
                }
                count = 0;
                chs = 0;
            }
        }
        string line;
        for(int i = index - count; i < index; i++)
            line += words[i] + " ";
        line.resize(maxWidth, ' ');
        ret.push_back(line);
        return ret;
    }
};