// https://leetcode.com/problems/sender-with-largest-word-count/

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        auto cnt_word = [&](int idx) -> int {
            int ret = 1;
            for(int i = 0; i < messages[idx].length(); i++){
                if(messages[idx][i] == ' ') ret++;
            }
            return ret;
        };
        
        map<string, int> mp;
        int len = messages.size();
        for(int i = 0; i < len; i++){
            mp[senders[i]] += cnt_word(i);
        }
        priority_queue<pair<int, string>> pq;
        for(auto it:mp){
            pq.push(make_pair(it.second, it.first));
        }
        return pq.top().second;
    }
};