// https://leetcode-cn.com/problems/bus-routes/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int len = routes.size();
        if(source == target) return 0;
        vector<vector<bool> > graph(len + 2, vector<bool>(len + 2, 0));
        routes.insert(routes.begin(), vector<int>(1, source));
        routes.push_back(vector<int>(1, target));
        for(int i = 0; i < len + 2; i++){
            for(int j = i + 1; j < len + 2; j++){
                vector<int> temp;
                set_intersection(routes[i].begin(), routes[i].end(), routes[j].begin(), routes[j].end(), back_inserter(temp));
                if(!temp.empty()){
                    graph[i][j] = 1;
                    graph[j][i] = 1;
                }
            }
        }
        
        auto min_dist = [&](vector<int>& dist, vector<bool>& avail_set) {
            int min_val = INT_MAX, min_idx = -1;
            for(int i = 0; i < len + 2; i++){
                if(!avail_set[i] && dist[i] <= min_val){
                    min_val = dist[i];
                    min_idx = i;
                }
            }
            return min_idx;
        };
        
        auto dijkstra = [&](int src) -> vector<int> {
            vector<int> dist(len + 2, INT_MAX);
            vector<bool> avail_set(len + 2, false);
            dist[src] = 0;
            for(int i = 0; i < len + 1; i++){
                int u = min_dist(dist, avail_set);
                avail_set[u] = true;
                for(int v = 0; v < len + 2; v++){
                    if(!avail_set[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                        dist[v] = dist[u] + graph[u][v];
                    }
                }
            }
            return dist;
        };
        int res = dijkstra(0).back();

        return res == INT_MAX? -1: res - 1;
    }
};