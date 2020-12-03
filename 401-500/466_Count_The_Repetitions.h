#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.length(), len2 = s2.length();
        vector<int> countindex(len2, - 1), indexcount1(len2, - 1), indexcount2(len2, - 1);
        int cycle1 = 0, cycle2 = 0;
        int i2 = 0;
        for(int count1 = 0, count2 = 0; ;count1++){
            if(indexcount1[i2] != -1){
                cycle1 = count1 - indexcount1[i2];
                cycle2 = count2 - indexcount2[i2];
                break;
            }
            else{
                countindex[count1] = i2;
                indexcount1[i2] = count1;
                indexcount2[i2] = count2; 
            }

            for(int i1 = 0; i1 < len1; i1++){
                if(s1[i1] == s2[i2]){
                    if(++i2 == len2){
                        i2 = 0;
                        count2++;
                    }
                }
            }
        }

        if(cycle2 == 0) return 0;

        return ((n1 - indexcount1[i2]) / cycle1 * cycle2 + indexcount2[countindex[indexcount1[i2] + (n1 - indexcount1[i2]) % cycle1]]) / n2;
    }
};

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.length(), len2 = s2.length();
        vector<int> indexcount1(len2, - 1), count1count2(len2, - 1);
        int cycle1 = 0, cycle2 = 0;
        int i2 = 0;
        for(int count1 = 0, count2 = 0; ;count1++){
            if(indexcount1[i2] != -1){
                cycle1 = count1 - indexcount1[i2];
                cycle2 = count2 - count1count2[indexcount1[i2]];
                break;
            }
            else{
                indexcount1[i2] = count1;
                count1count2[count1] = count2;
            }

            for(int i1 = 0; i1 < len1; i1++){
                if(s1[i1] == s2[i2]){
                    if(++i2 == len2){
                        i2 = 0;
                        count2++;
                    }
                }
            }
        }

        if(cycle2 == 0) return 0;

        return ((n1 - indexcount1[i2]) / cycle1 * cycle2 + count1count2[indexcount1[i2] + (n1 - indexcount1[i2]) % cycle1]) / n2;
    }
};