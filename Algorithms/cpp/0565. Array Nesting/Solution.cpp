// https://leetcode.com/problems/array-nesting/

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), res = 0;;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            int cnt = 0, tmp = i;
            while(!visited[tmp]){
                visited[tmp] = true;
                tmp = nums[tmp];
                cnt++;
            }
            res = max(res, cnt);
        }
        return res;
    }
};