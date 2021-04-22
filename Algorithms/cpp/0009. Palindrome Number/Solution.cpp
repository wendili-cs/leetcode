// https://leetcode-cn.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        long x_recon = 0, temp = x;
        while(temp > 0){
            x_recon = x_recon*10 + (temp % 10);
            temp = temp/10;
        }
        return x_recon == x;
    }
};