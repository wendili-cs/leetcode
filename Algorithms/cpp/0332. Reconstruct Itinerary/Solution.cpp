// https://leetcode.com/problems/reconstruct-itinerary/

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, set<string>> mp;
        unordered_map<string, unordered_map<string, int>> visited, total;
        for(auto& ticket:tickets){
            mp[ticket[0]].insert(ticket[1]);
            total[ticket[0]][ticket[1]]++;
        }
        vector<string> res;
        function<bool(string)> dfs;
        dfs = [&](string start) -> bool {
            if(res.size() == tickets.size() + 1) return true;
            for(string next:mp[start]){
                string route = start + "-" + next;
                if(visited[start][next] >= total[start][next]) continue; // we don't use one ticket twice
                visited[start][next]++;
                res.push_back(next);
                if(dfs(next)) return true; // we stop dfs once we find an available route
                res.pop_back();
                visited[start][next]--;
            }
            return false;
        };
        res.push_back("JFK"); // start from here
        dfs("JFK");
        return res;
    }
};