// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int res = 0;
        for(string word:words){
            mp[word]++;
            if(word[0] != word[1]){
                string rword(word.rbegin(), word.rend());
                if(mp[rword] > 0){
                    mp[rword]--;
                    mp[word]--;
                    res += 4;
                }
            }
            else if(mp[word] > 1){
                mp[word] -= 2;
                res += 4;
            }
        }
        for(auto it:mp){
            if(it.first[0] == it.first[1] && it.second > 0){
                res += 2;
                break;
            }
        }
        return res;
    }
};