// https://leetcode-cn.com/problems/implement-rand10-using-rand7/

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int r;
        while(true){
            r = (rand7() - 1)*7 + rand7();
            if(r <= 40) break;
        }
        return r%10 + 1;
    }
};