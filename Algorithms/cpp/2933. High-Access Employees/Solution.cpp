// https://leetcode.com/contest/weekly-contest-371/problems/high-access-employees/

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> res;
        unordered_map<string, vector<string>> mp;
        for(auto access:access_times){
            mp[access[0]].push_back(access[1]);
        }
        
        auto cal_minutes = [](string a, string b) -> int {
            // assume a > b
            int hours = stoi(a.substr(0, 2)) - stoi(b.substr(0, 2));
            int minutes = stoi(a.substr(2, 2)) - stoi(b.substr(2, 2));
            return hours*60 + minutes;
        };
        
        auto is_high_access = [&](vector<string> &vec) -> bool {
            // determine if the string vector is high access
            int l = 0, r = 0, len = vec.size();
            while(r < len){
                while(cal_minutes(vec[r], vec[l]) >= 60){
                    l++;
                }
                if(r - l + 1 >= 3){
                    return true;
                }
                r++;
            }
            return false;
        };
        
        for(auto it:mp){
            sort(it.second.begin(), it.second.end());
            if(is_high_access(it.second)){
                res.push_back(it.first);
            }
        }
        return res;
    }
};