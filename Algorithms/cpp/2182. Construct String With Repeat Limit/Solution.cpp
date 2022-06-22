// https://leetcode.com/problems/construct-string-with-repeat-limit/

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string res;
        vector<int> cnt(26, 0);
        for(char& c:s) cnt[c - 'a']++;
        priority_queue<pair<char,int>> pq;
        for(int i = 0; i < 26; i++) {
            if(cnt[i]) pq.push(make_pair(i + 'a', cnt[i]));
        }
        while(!pq.empty()){
            char c = pq.top().first;
            int n = pq.top().second;
            pq.pop();
            if(res.empty() || res.back() != c){
                int rep_num = min(repeatLimit, n);
                for(int i = 0; i < rep_num; i++){
                    res.push_back(c);
                }
                if(rep_num < n) pq.push(make_pair(c, n - rep_num));
            }
            else{ // add
                if(pq.empty()) break;
                char c2 = pq.top().first;
                int n2 = pq.top().second;
                pq.pop();
                res.push_back(c2);
                if(n2 > 1) pq.push(make_pair(c2, n2 - 1));
                pq.push(make_pair(c, n));
            }
        }
        return res;
    }
};