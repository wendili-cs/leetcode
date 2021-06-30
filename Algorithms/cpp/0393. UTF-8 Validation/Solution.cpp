// https://leetcode-cn.com/problems/utf-8-validation/

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        auto to_bit = [](int num) -> string {
            string ret = "";
            for(int i = 0; i < 8; i++){
                ret = (num%2==1?"1":"0") + ret;
                num >>= 1;
            } 
            return ret;
        };
        string t;
        int cnter = 0;
        for(int i = 0; i < data.size(); i++){
            t = to_bit(data[i]);
            cnter = 0;
            while(cnter <= 8 && t[cnter] != '0') cnter++;
            if(cnter > 4 || cnter == 1 || i + cnter > data.size()) return false;
            for(int j = 1; j < cnter; j++){
                t = to_bit(data[i + j]);
                if(t.substr(0, 2) != "10") return false;
            }
            if(cnter != 0) i += cnter - 1;
        }
        return true;
    }
};