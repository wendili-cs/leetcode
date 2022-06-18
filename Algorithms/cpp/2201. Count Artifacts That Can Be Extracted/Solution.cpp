// https://leetcode.com/problems/count-artifacts-that-can-be-extracted/

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        map<pair<int,int>, int> xy2art;
        map<int, set<pair<int,int>>> art2pts;
        for(int k = 0; k < artifacts.size(); k++){
            for(int i = artifacts[k][0]; i <= artifacts[k][2]; i++){
                for(int j = artifacts[k][1]; j <= artifacts[k][3]; j++){
                    xy2art[make_pair(i,j)] = k;
                    art2pts[k].insert(make_pair(i, j));
                }
            }
        }
        int res = 0;
        for(auto& d:dig){
            auto temp = make_pair(d[0], d[1]);
            int id = xy2art[temp];
            if(art2pts[id].find(temp) != art2pts[id].end()){
                art2pts[id].erase(temp);
                if(art2pts[id].empty()) res++;
            }
        }
        return res;
    }
};