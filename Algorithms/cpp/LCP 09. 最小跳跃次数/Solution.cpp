// https://leetcode-cn.com/problems/zui-xiao-tiao-yue-ci-shu/

class Solution {
public:
    int minJump(vector<int>& jump) {
        int len = jump.size(), res = 0, far = 1;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                int cur = q.front();
                q.pop();
                if(cur + jump[cur] >= len) return res + 1;
                if(cur + jump[cur] >= far) q.push(cur + jump[cur]);
                for(int j = far; j < cur; j++) q.push(j);
                far = max(far, cur + 1);
            }
            res++;
        }
        return res;
    }
};