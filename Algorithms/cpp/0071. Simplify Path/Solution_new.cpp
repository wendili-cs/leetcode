// https://leetcode.com/problems/simplify-path/

class Solution {
public:
    string simplifyPath(string path) {
        deque<string> stk;
        stringstream ss(path);
        string tmp;
        char delim = '/';
        while(getline(ss, tmp, delim)){
            if(tmp.empty()) continue;
            int idx;
            for(idx = 0; idx < tmp.length() && tmp[idx] == '.'; idx++); 
            // tmp is like '...' and is not a folder
            if(idx == tmp.length()){
                if(tmp.length() == 2 && !stk.empty()){
                    stk.pop_back();
                }
                else if(tmp.length() > 2){
                    stk.push_back(tmp);
                }
            }
            else{
                stk.push_back(tmp);
            }
        }
        string res;
        while(!stk.empty()){
            res += '/' + stk.front();
            stk.pop_front();
        }
        return res.empty() ? "/" : res;
    }
};