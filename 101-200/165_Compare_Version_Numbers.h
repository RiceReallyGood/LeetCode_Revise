#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int index1 = 0, index2 = 0;
        while(index1 < version1.length() || index2 < version2.length()){
            int num1 = 0;
            while(index1 < version1.length() && version1[index1] != '.')
                num1 = num1 * 10 + version1[index1++] - '0';
            int num2 = 0;
            while(index2 < version2.length() && version2[index2] != '.')
                num2 = num2 * 10 + version2[index2++] - '0';
            if(num1 < num2) return -1;
            if(num1 > num2) return 1;
            index1++;
            index2++;
        }
        return 0;
    }
};