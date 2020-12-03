#include <string>
using namespace std;

class Solution {
public:
    int kSimilarity(string A, string B) {
        //preprocess
        int precnt = 0;
        for(int i = 0; i < A.size(); i++){
            if(A[i] == B[i]) continue;

            for(int j = i + 1; j < A.size(); j++){
                if(A[i] == B[j] && A[j] == B[i]){
                    swap(B[i], B[j]);
                    precnt++;
                    break;
                }
            }
        }
        string preA, preB;
        for(int i = 0; i < A.size(); i++){
            if(A[i] == B[i]) continue;
            preA.push_back(A[i]);
            preB.push_back(B[i]);
        }
        return precnt + Similarity(preA, preB, 0);
    }

private:
    int Similarity(const string& target, string& s, int index){
        if(index == target.length()) return 0;

        if(target[index] == s[index])
            return Similarity(target, s, index + 1);
        
        int minswap = target.length();

        for(int i = index + 1; i < target.length(); i++){
            if(s[i] == target[index]){
                swap(s[index], s[i]);
                minswap = min(minswap, Similarity(target, s, index + 1));
                swap(s[index], s[i]);
                if(s[index] == target[i]) break;
            }
        }

        return minswap + 1;
    }
};