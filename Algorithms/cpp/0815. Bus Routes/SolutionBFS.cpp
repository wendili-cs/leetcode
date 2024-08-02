// https://leetcode.com/problems/bus-routes/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        unordered_map<int, unordered_set<int>> stop2bus;
        for(int i = 0; i < routes.size(); i++){
            for(int stop:routes[i]) stop2bus[stop].insert(i);
        }
        queue<int> q; // bus queue
        unordered_set<int> visited_bus;
        for(int bus:stop2bus[source]){
            q.push(bus);
            visited_bus.insert(bus);
        }
        int res = 0;
        while(!q.empty()){
            res++;
            int qsize = q.size();
            for(int i = 0; i < qsize; i++){
                int bus = q.front();
                q.pop();
                for(int stop:routes[bus]){
                    if(stop == target) return res;
                    for(int next_bus:stop2bus[stop]){
                        if(visited_bus.find(next_bus) == visited_bus.end()){
                            q.push(next_bus);
                            visited_bus.insert(next_bus);
                        }
                    }
                }
            }
        }
        return -1;
    }
};