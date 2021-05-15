// https://leetcode-cn.com/problems/basic-calculator-ii/

class Solution {
public:
    int calculate(string s) {
        vector<string> stk;
        string temp;
        for(char& c:s){
            if(c == ' ') continue;
            else if(c == '+' || c == '-'){ //|| c == '*' || c == '/'
                if(!temp.empty()) stk.push_back(temp);
                // temp = "";
                // temp += c;
                string c_s(1,c);
                stk.push_back(c_s);
                temp = "";
            }
            else temp += c;
        }
        if(!temp.empty()) stk.push_back(temp);
        // vector<char> sub_exp;
        for(int i = 0; i < stk.size(); i++){
            if(stk[i] == "+" || stk[i] == "-") continue;
            int product = 1, num = 0;
            bool is_product = true;
            for(int j = 0; j < stk[i].length() + 1; j++){
                if(stk[i][j] != '*' && stk[i][j] != '/' && j != stk[i].length()){
                    num = num*10 + (stk[i][j] - '0');
                }
                else{
                    if(is_product) product = product*num;
                    else product = product/num;
                    if(j != stk[i].length()){
                        if(stk[i][j] == '/') is_product = false;
                        else is_product = true;
                        num = 0;
                    }
                }
            }
            stk[i] = to_string(product);
        }
        bool is_add;
        int res = 0;
        while(!stk.empty()){
            int num = stoi(stk.back());
            stk.pop_back();
            if(stk.empty()) is_add = true;
            else{
                if(stk.back() == "-") is_add = false;
                else is_add = true;
                stk.pop_back();
            }
            res = is_add? (res + num):(res - num);
        }
        temp = "";
        return res;
    }
};