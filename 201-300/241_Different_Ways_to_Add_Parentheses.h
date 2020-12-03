#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> ops;

        int num = 0;
        for(int i = 0; i <= input.size(); i++){
            if(i == input.size()){
                nums.push_back(num);
                break;
            }
            if(input[i] == ' ') continue;

            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                nums.push_back(num);
                num = 0;
                ops.push_back(input[i]);
            }
            else{
                num = num * 10 + (input[i] - '0');
            }
        }

        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n)); 

        for(int i = 0; i < n; i++)
            dp[i][i].push_back(nums[i]);
        
        for(int len = 2; len <= n; len++){
            for(int i = 0; i + len <= n; i++){
                int j = i + len - 1;
                for(int k = i; k < j; k++){
                    for(int num1 : dp[i][k])
                        for(int num2 : dp[k + 1][j])
                            dp[i][j].push_back(eval(ops[k], num1, num2));
                }
            }
        }
        return dp[0][n - 1];
    }

private:
    int eval(char op, int num1, int num2){
        if(op == '+') return num1 + num2;
        else if(op == '-') return num1 - num2;
        else return num1 * num2;
    }
};