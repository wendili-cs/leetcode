// https://leetcode-cn.com/problems/is-unique-lcci/

class Solution {
public:
    bool isUnique(string astr) {
        long long marks = 0;
        for(char& c:astr){
            int shifts = c - 'a';
            if(marks & (1 << shifts)) return false;
            marks = marks | (1 << shifts);
        }
        return true;
    }
};