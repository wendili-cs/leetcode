// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<int> cnts;
        for(int i = 0; i < s.length(); i++){
            if(i == 0 || s[i] != s[i - 1]){
                cnts.push(1);
            }
            else if(cnts.top() == k - 1){
                s.erase(i - k + 1, k);
                i = i - k;
                cnts.pop();
            }
            else cnts.top()++;
        }
        return s;
    }
};