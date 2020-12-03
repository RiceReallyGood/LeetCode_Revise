#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;

        for(int i = 1; i <= n; i++){
            if(i % 3 == 0){
                if(i % 5 == 0)
                    ret.emplace_back("FizzBuzz");
                else
                    ret.emplace_back("Fizz");
            }
            else if(i % 5 == 0){
                ret.emplace_back("Buzz");
            }
            else
                ret.emplace_back(to_string(i));
        }

        return ret;
    }
};