// https://leetcode.com/problems/number-of-same-end-substrings/

class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        vector<int> anagram(26, 0);
        vector<vector<int>> patterns;
        patterns.push_back(anagram);
        for(char &c:s){
            anagram[c - 'a']++;
            patterns.push_back(anagram);
        }
        vector<int> res;
        for(auto& q:queries){
            int ret = q[1] + 1 - q[0]; // each single char
            for(int i = 0; i < 26; i++){
                int num_letter = patterns[q[1] + 1][i] - patterns[q[0]][i];
                if(num_letter > 1){
                    ret += num_letter*(num_letter - 1)/2;
                }
            }
            res.push_back(ret);
        }
        return res;
    }
};

// Input: s = "abcaab", queries = [[0,0],[1,4],[2,5],[0,5]]
// Output: [1,5,5,10]