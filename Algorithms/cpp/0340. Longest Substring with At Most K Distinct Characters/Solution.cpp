// https://leetcode-cn.com/problems/longest-substring-with-at-most-k-distinct-characters/

// 要点：双指针，用一个hash当计数器
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // if(k == 0) return 0;
        int l = 0, r = 0, max_len = 0;
        unordered_map<int, int> cnter;
        for(r = 0; r < s.length(); r++){
            cnter[s[r]]++;
            while(cnter.size() > k){
                if(cnter[s[l]] <= 1) cnter.erase(cnter.find(s[l]));
                else cnter[s[l]]--;
                l++;
            }
            max_len = max(max_len, r - l + 1);
        }
        return max_len;
    }
};