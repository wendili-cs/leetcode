// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), cmp);
        
        int res = 0, max_def = INT_MIN, len = properties.size();
        for(int i = len - 1; i >= 0; i--){
            if(properties[i][1] < max_def) res++;
            else max_def = max(max_def, properties[i][1]);
        }
        return res;
    }
};