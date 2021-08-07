// https://leetcode-cn.com/problems/alien-dictionary/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        // 生成边
        map<char, vector<char> > edges;
        map<char, int> indegree;
        for(int i = 0; i < words.size(); i++)
            for(char& c:words[i])
                indegree[c] = 0;
        for(int i = 0; i < words.size() - 1; i++){
            int len = min(words[i].size(), words[i + 1].size());
            for(int j = 0; j < len; j++){
                if(words[i][j] != words[i + 1][j]){
                    edges[words[i][j]].push_back(words[i + 1][j]);
                    indegree[words[i + 1][j]]++;
                    break;
                }
                else if(j == len - 1 && words[i].length() > words[i + 1].length()) return "";
            }
        }
        // 拓扑排序
        deque<char> proc;
        for(auto it:indegree){
            if(it.second == 0) proc.push_back(it.first);
        }
        string res;
        while(!proc.empty()){
            for(char c:edges[proc.front()]){
                if(--indegree[c] == 0) proc.push_back(c);
            }
            res.push_back(proc.front());
            proc.pop_front();
        }
        return res.length()==indegree.size()?res:"";
    }
};