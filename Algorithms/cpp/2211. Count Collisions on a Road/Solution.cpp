// https://leetcode.com/problems/count-collisions-on-a-road/

class Solution {
public:
    int countCollisions(string directions) {
        stack<char> cur; // none
        int res = 0;
        for(int i = 0; i < directions.size(); i++){
            if((directions[i] == 'L' || directions[i] == 'S') && !cur.empty()){
                if(directions[i] == 'L') res++;
                while(!cur.empty()){
                    if(cur.top() == 'R') res++;
                    cur.pop();
                }
                cur.push('S');
            }
            else if(directions[i] == 'R' || (cur.empty() && directions[i] == 'S')) cur.push(directions[i]);
        }
        return res;
    }
};