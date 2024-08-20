// https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() < b.length()) swap(a, b); // length: a > b
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int idx = 0, m = a.length(), n = b.length(), carry = 0;
        string res;
        while(idx < m){
            int x = a[idx] == '1'; // current char on a
            int y = idx < n && b[idx] == '1'; // current char on b
            int z = (x + y + carry)%2; // current char on result
            res.push_back(z + '0');
            carry = x + y + carry > 1;
            idx++;
        }
        if(carry > 0) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};