class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int, int> >s;
        multiset<int> h;
        h.insert(0); // 初始化地面
        vector<vector<int> >res;
        for(auto& building:buildings){ // 这里先-后+，同一个区域就会先更新新的，再删去旧的，不会出现触底0的问题
            s.emplace(building[0], -building[2]);
            s.emplace(building[1], building[2]);
        }
        int cur_max = 0;
        for(auto& p:s){
            if(p.second < 0) h.insert(-p.second);
            else h.erase(h.find(p.second)); // 只擦掉一个
            if(cur_max != *h.rbegin()){
                cur_max = *h.rbegin();
                res.push_back({p.first, cur_max});
            }
        }
        return res;
    }
};