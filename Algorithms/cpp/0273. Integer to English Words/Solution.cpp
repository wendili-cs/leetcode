// https://leetcode-cn.com/problems/integer-to-english-words/

class Solution {
private:
    vector<string> HU = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> TW = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string helper(int n){
        string s;
        if(n < 20) s = TW[n];
        else if(n < 100) s = HU[n/10] + " " + TW[n%10];
        else if(n < 1000) s = helper(n/100) + " Hundred " + helper(n%100);
        else if(n < 1000000) s = helper(n/1000) + " Thousand " + helper(n%1000);
        else if(n < 1000000000) s = helper(n/1000000) + " Million " + helper(n%1000000);
        else s = helper(n/1000000000) + " Billion " + helper(n%1000000000);
        while(!s.empty() && s[s.length() - 1] == ' ') s.erase(s.end() - 1);
        return s;
    }
public:
    string numberToWords(int num) {
        return num == 0?"Zero":helper(num);
    }
};