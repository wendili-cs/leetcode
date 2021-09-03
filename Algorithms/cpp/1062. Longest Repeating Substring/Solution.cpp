// https://leetcode-cn.com/problems/longest-repeating-substring/

class Solution {
public:
    int longestRepeatingSubstring(string s) {
        auto search = [&](int len) -> int {
            unordered_set<string> st;
            for(int i = 0; i + len - 1 < s.length(); i++){
                string temp = s.substr(i, len);
                if(st.find(temp) != st.end()) return len;
                st.insert(temp);
            }
            return 0;
        };
        // len如果可以，那么len - 1也可以，所以是单调的，二分查找
        int l = 0, r = s.length() - 1, res = 0;
        while(l <= r){
            int len = (l + r)/2;
            int ret = search(len);
            
            if(ret == 0) r = len - 1;
            else{
                res = max(res, len);
                l = len + 1;
            }
        }
        return res;
    }
};