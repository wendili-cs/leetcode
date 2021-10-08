// https://leetcode.com/problems/valid-square/

class Solution {
public:
    int calc_dis(vector<int> &pt1, vector<int> &pt2){
        return (pt1[0]-pt2[0])*(pt1[0]-pt2[0]) + (pt1[1]-pt2[1])*(pt1[1]-pt2[1]);
    }
    bool is_vertical(vector<int> &c, vector<int> &l, vector<int> &r){
        return (c[0]-l[0])*(c[0]-r[0])+(c[1]-l[1])*(c[1]-r[1]) == 0;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> p = {p1, p2, p3, p4};
        set<pair<int, int>> s;
        for(auto &ep:p){
            if(s.find(make_pair(ep[0], ep[1])) != s.end()) return false;
            else s.insert(make_pair(ep[0], ep[1]));
        }
        sort(p.begin() + 1, p.end(), 
             [&](vector<int> &a, vector<int> &b)->bool{
                 return calc_dis(a, p1) < calc_dis(b, p1);
             });
        if(calc_dis(p[0], p[1]) == calc_dis(p[0], p[2]) && calc_dis(p[0], p[1]) == calc_dis(p[1], p[3]) && calc_dis(p[0], p[1]) == calc_dis(p[2], p[3])){ // 距离相等
            if(is_vertical(p[0], p[1], p[2]))
                return true;
        }
        return false;
    }
};