// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0;
        queue<int> q;
        for(string& str:bank){
            int tmp = 0;
            for(char& c:str){
                if(c == '1') tmp++;
            }
            if(tmp) q.push(tmp);
            if(q.size() == 2){
                res += q.front()*q.back();
                q.pop();
            }
        }
        return res;
    }
};