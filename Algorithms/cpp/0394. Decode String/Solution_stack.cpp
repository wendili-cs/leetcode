// https://leetcode-cn.com/problems/decode-string/

class Solution {
public:
    static string cp_str(string s, int num){
        string res = "";
        for(int i = 0; i < num; i++){
            res += s;
        }
        return res;
    }

    string decodeString(string s) {
        string res;
        vector<string> stk_str;
        // stack<int> stk_num;
        int len = s.length();
        int i = 0;
        // int rep_num = 1;
        // if(!(isdigit(s[i]))) stk_num.push(1);
        while(i < len){
            if(isdigit(s[i])){
                int start_idx = i;
                while(isdigit(s[i])){
                    i++;
                }
                stk_str.push_back(s.substr(start_idx, i - start_idx));
            }
            else if(isalpha(s[i])){
                string t_str = "";
                while(isalpha(s[i])){
                    t_str += s[i];
                    i++;
                }
                stk_str.push_back(t_str);
            }
            else if(s[i] == '['){
                stk_str.push_back(string(1, s[i]));
                i++;
            }
            else if(s[i] == ']'){
                i++;
                string sub;
                while(stk_str.back() != "["){
                    sub = stk_str.back() + sub;
                    stk_str.pop_back(); // 弹出子字符串
                }
                stk_str.pop_back(); // 弹出[
                int rep_num = stoi(stk_str.back());
                stk_str.pop_back(); // 弹出数字string
                string t = cp_str(sub, rep_num);
                stk_str.push_back(t);
                
            }
        }
        for(const auto& s:stk_str){
            res += s;
        }
        return res;
    }
};