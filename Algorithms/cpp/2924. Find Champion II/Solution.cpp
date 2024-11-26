// https://leetcode.com/problems/find-champion-ii/

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> lose(n, false);
        for(auto& e:edges){
            lose[e[1]] = true;
        }
        int champ = -1;
        for(int i = 0; i < n; i++){
            if(!lose[i]){
                if(champ != -1) return -1; // 两个以上的不败者
                champ = i;
            }
        }
        return champ;
    }
};