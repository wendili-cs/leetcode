// https://leetcode-cn.com/problems/word-ladder/

class Solution {
private:
    unordered_map<string, int> word2id;
    vector<vector<int> > edge;
    int cur_id = 0;
public:
    void add_word(string& word){
        if(word2id.find(word) == word2id.end()){
            word2id[word] = cur_id++;
            edge.emplace_back();
        }
    }

    void add_edge(string& word){
        add_word(word);
        int id1 = word2id[word];
        for(char& c:word){
            char temp = c;
            c = '*';
            add_word(word);
            int id2 = word2id[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            c = temp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(string& word:wordList) add_edge(word);
        if(word2id.find(endWord) == word2id.end()) return 0;
        add_edge(beginWord);
        
        vector<int> dis_begin(cur_id, INT_MAX), dis_end(cur_id, INT_MAX);
        int begin_id = word2id[beginWord], end_id = word2id[endWord];
        dis_begin[begin_id] = dis_end[end_id] = 0;
        queue<int> q_begin, q_end;
        q_begin.push(begin_id);
        q_end.push(end_id);

        while(!q_begin.empty() && !q_end.empty()){
            int q_size = q_begin.size();
            for(int i = 0; i < q_size; i++){
                int node_id = q_begin.front();
                q_begin.pop();
                if(dis_end[node_id] != INT_MAX) return (dis_begin[node_id] + dis_end[node_id])/2 + 1;
                for(int id:edge[node_id]){
                    if(dis_begin[id] == INT_MAX){
                        dis_begin[id] = dis_begin[node_id] + 1;
                        q_begin.push(id);
                    }
                }
            }

            q_size = q_end.size();
            for(int i = 0; i < q_size; i++){
                int node_id = q_end.front();
                q_end.pop();
                if(dis_begin[node_id] != INT_MAX) return (dis_begin[node_id] + dis_end[node_id])/2 + 1;
                for(int id:edge[node_id]){
                    if(dis_end[id] == INT_MAX){
                        dis_end[id] = dis_end[node_id] + 1;
                        q_end.push(id);
                    }
                }
            }
        }
        return 0;
    }
};