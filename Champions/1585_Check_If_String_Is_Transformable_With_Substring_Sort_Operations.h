#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isTransformable(string s, string t) {
        if(!ispermutation(s, t)) return false;
        vector<vector<int>> invs(10, vector<int>(10));
        vector<vector<int>> invt(10, vector<int>(10));
        getinversepairs(s, invs);
        getinversepairs(t, invt);
        for(int i = 0; i < 10; i++){
            for(int j = i + 1; j < 10; j++){
                if(invs[i][j] < invt[i][j])
                    return false;
            }
        }
        return true;
    }

private:
    bool ispermutation(const string& s, const string& t){
        if(s.length() != t.length()) return false;
        int count[10] {0};
        for(int i = 0; i < s.length(); i++)
            count[s[i] - '0']++;
        
        for(int i = 0; i < t.length(); i++)
            count[t[i] - '0']--;
        
        for(int i = 0; i < 10; i++)
            if(count[i] != 0)
                return false;
        
        return true;
    }

    void getinversepairs(const string& s, vector<vector<int>>& invs){
        for(int c = '1'; c <= '9'; c++){
            int count = 0;
            for(int i = 0; i < s.length(); i++){
                if(s[i] == c) count++;
                else if(s[i] < c){
                    invs[s[i] - '0'][c - '0'] += count;
                }
            }
        }
    }
};