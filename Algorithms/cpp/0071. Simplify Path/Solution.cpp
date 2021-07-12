// https://leetcode-cn.com/problems/simplify-path/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        // stk.push("/");
        int l = 0;
        if(path[path.length() - 1] != '/') path += "/";
        for(int r = 0; r < path.length(); r++){
            if(path[r] == '/' && l != r){
                string temp = path.substr(l + 1, r - l - 1);
                l = r;
                if(temp.empty()) continue;
                int idx;
                for(idx = 0; temp[idx] == '.' && idx < temp.length(); idx++);
                if(idx == temp.length() && stk.size() >= temp.length() - 1){ // temp是纯...的路径且不是...的文件夹
                    for(int i = 0; i < temp.length() - 1; i++) stk.pop();
                }
                else if(temp != "..") stk.push(temp);
            }
        }
        string res = "";
        while(!stk.empty()){
            res = "/" + stk.top() + res;
            stk.pop();
        }
        return res.empty()?"/":res;
    }
};