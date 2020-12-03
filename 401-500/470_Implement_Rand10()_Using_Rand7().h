int rand7();

class Solution {
public:
    int rand10() {
        while(true){
            int num = (rand7() - 1) * 7 + rand7() - 1;
            if(num < 40) return num % 10 + 1;

            num = (num - 40) * 7 + rand7() - 1;
            if(num < 60) return num % 10 + 1;

            num = (num - 60) * 7 + rand7() - 1;
            if(num < 20) return num % 10 + 1;
        }
    }
};