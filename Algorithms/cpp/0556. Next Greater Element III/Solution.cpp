// https://leetcode-cn.com/problems/next-greater-element-iii/

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int l = s.length() - 2, r = s.length() - 1;
        while(l >= 0 && s[l] >= s[l + 1]) l--;
        if(l >= 0){
            while(s[l] >= s[r]) r--;
            swap(s[l], s[r]);
        }
        reverse(s.begin() + l + 1, s.end());
        // 如果 超范围了 or 转回去了
        if((s.length()==10 && s > "2147483647") || stoi(s) <= n) return -1;
        return stoi(s);
    }
};