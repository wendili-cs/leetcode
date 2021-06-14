// https://leetcode-cn.com/problems/accounts-merge/

class Solution {
public:
    static bool cmp(vector<string> &a, vector<string> &b) {return a[0] > b[0];}
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        if(accounts.size() == 1) return accounts;
        // 查并集
        vector<int> cbj(accounts.size());
        for(int i = 0; i < accounts.size(); i++) cbj[i] = i;
        function<int(int)> find;
        find = [&](int i) -> int {
            if(cbj[i] != i) cbj[i] = find(cbj[i]);
            return cbj[i];
        };
        unordered_map<string, int> e2i;
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(e2i.find(accounts[i][j]) == e2i.end()) e2i[accounts[i][j]] = i;
                else cbj[find(i)] = find(cbj[e2i[accounts[i][j]]]);
            }
        }
        // 把对应的账号id更新成root id
        for(auto &iter:e2i) iter.second = find(iter.second);
        // 还原成用户->邮箱
        vector<vector<string> >res(accounts.size());
        for(auto &iter:e2i){
            if(res[iter.second].empty()) res[iter.second].push_back(accounts[iter.second][0]);
            res[iter.second].push_back(iter.first);
        }
        for(int i = 0; i < res.size(); i++){
            if(res[i].empty()){
                res.erase(res.begin() + i);
                i--;
            }
            else sort(res[i].begin() + 1, res[i].end(), less<string>()); // 名字不排序
        }
        return res;
    }
};