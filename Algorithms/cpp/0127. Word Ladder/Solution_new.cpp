// https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, unordered_set<string>> mp;
        auto cal_dis = [](string &a, string &b){
            int ret = 0;
            for(int i = 0; i < a.length(); i++){
                if(a[i] != b[i]) ret++;
            }
            return ret;
        };
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        int res = 1;
        while(!q.empty()){
            int qsize = q.size();
            for(int i = 0; i < qsize; i++){
                string cur = q.front();
                q.pop();
                if(cur == endWord) return res;
                for(string &word:wordList){
                    if(visited.find(word) == visited.end() && cal_dis(cur, word) == 1){
                        visited.insert(word);
                        q.push(word);
                    }
                }
            }
            res++;
        }
        return 0;
    }
};