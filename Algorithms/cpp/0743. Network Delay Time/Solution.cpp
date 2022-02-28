class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int, vector<int>> u2v, u2w;
        map<int, int> dis;
        for(auto& t:times){
            u2v[t[0]].push_back(t[1]);
            u2w[t[0]].push_back(t[2]);
        }
        queue<pair<int, int>> q;
        q.push(make_pair(k, 0));
        while(!q.empty()){
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                auto p = q.front();
                q.pop();
                if(dis.find(p.first) != dis.end() && dis[p.first] <= p.second) continue;
                dis[p.first] = p.second;
                for(int j = 0; j < u2v[p.first].size(); j++){
                    int v = u2v[p.first][j], w = u2w[p.first][j];
                    q.push(make_pair(v, dis[p.first] + w));
                }
            }
        }
        int res = 0;
        for(auto it:dis) res = max(res, it.second);
        return dis.size() == n?res:-1;
    }
};