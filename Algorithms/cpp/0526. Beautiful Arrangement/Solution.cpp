// https://leetcode.com/problems/beautiful-arrangement/

class Solution {
public:
    int countArrangement(int n) {
        int res = 0;
        vector<bool> visited = vector<bool>(n, false);
        function<void(int)> recur;
        recur = [&](int pos) -> void {
            // pos refers to the number of placed numbers
            if(pos > n) {
                res++;
                return;
            }
            for(int i = 1; i <= n; i++){
                if(!visited[i - 1] && (i%pos==0||pos%i==0)){
                    visited[i - 1] = true;
                    recur(pos + 1);
                    visited[i - 1] = false;
                }
            }
        };
        recur(1);
        return res;
    }
};