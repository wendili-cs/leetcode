// https://leetcode.com/problems/analyze-user-website-visit-pattern/

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        map<string, map<string, map<string, int>>> pt; // pattern
        map<string, vector<pair<int, string>>> mp; // user -> (time, website)
        int n = username.size(), cmax = 0;
        vector<string> res(3);
        for(int i = 0; i < n; i++){
            mp[username[i]].emplace_back(timestamp[i], website[i]);
        }
        for(auto it:mp){
            int m = it.second.size();
            if(m < 3) continue;
            sort(it.second.begin(), it.second.end());
            unordered_set<string> tmp;
            for(int i = 0; i < m; i++){
                for(int j = i + 1; j < m; j++){
                    for(int k = j + 1; k < m; k++){
                        string s1 = it.second[i].second, s2 = it.second[j].second, s3 = it.second[k].second;
                        if(tmp.find(s1 + " " + s2 + " " + s3) != tmp.end()) continue;
                        int cur = ++pt[s1][s2][s3];
                        if(cur > cmax) cmax = cur;
                        tmp.insert(s1 + " " + s2 + " " + s3);
                    }
                }
            }
        }
        for(auto it1:pt){
            for(auto it2:it1.second){
                for(auto it3:it2.second){
                    if(it3.second == cmax){
                        res = {it1.first, it2.first, it3.first};
                        return res;
                    }
                }
            }
        }
        return {};
    }
};