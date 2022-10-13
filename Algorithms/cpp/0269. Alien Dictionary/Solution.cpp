// https://leetcode-cn.com/problems/alien-dictionary/
// https://leetcode.com/problems/alien-dictionary/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> edge;
        unordered_map<char, int> in;
        // initialize indegree
        for(string &word:words){
            for(char c:word){
                in[c] = 0;
            }
        }
        // build graph
        for(int i = 0; i < words.size() - 1; i++){
            int len = min(words[i].length(), words[i + 1].length());
            for(int j = 0; j < len; j++){
                if(words[i][j] != words[i + 1][j]){
                    edge[words[i][j]].push_back(words[i + 1][j]);
                    in[words[i + 1][j]]++;
                    break;
                }
                if(j == len - 1 && words[i].length() > words[i + 1].length()) return "";
            }
        }
        // topological sort
        queue<char> q;
        for(auto it:in){
            if(it.second == 0) q.push(it.first);
        }
        string res;
        while(!q.empty()){
            char c = q.front();
            q.pop();
            for(int i = 0; i < edge[c].size(); i++){
                if(--in[edge[c][i]] == 0) q.push(edge[c][i]);
            }
            res.push_back(c);
        }
        return res.length() == in.size() ? res : "";
    }
};