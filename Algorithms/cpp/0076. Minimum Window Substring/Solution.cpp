// https://leetcode-cn.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cnt, t_dict;
        for(const auto& c:t){
            t_dict[c]++;
        }
        auto check = [&]() -> bool {
            for(const auto& p:t_dict){
                if(cnt[p.first] < p.second){ // 只要cnt里面的某个字符的次数小于t_dict，则没覆盖全
                    return false;
                }
            }
            return true;
        };
        int str_len = s.length(), l = 0, r = -1, len = INT_MAX, l_begin = -1;
        while(r < str_len){
            r++;
            if(t_dict.count(s[r]) > 0){
                cnt[s[r]]++;
            }
            while(check() && l <= r){
                if(r - l + 1 < len){
                    len = r - l + 1;
                    l_begin = l;
                }
                if(t_dict.find(s[l]) != t_dict.end()){ // s[l]存在于t中，则去掉了s[l]要减少
                    cnt[s[l]]--;
                }
                l++;
            }

        }

        return l_begin == -1? "":s.substr(l_begin, len);
    }
};