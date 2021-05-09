// https://leetcode-cn.com/problems/group-anagrams/
// 超时...

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> cnts;
        vector<vector<string> > res;
        auto index_cnt = [&](vector<int>& cnt) -> int {
            for(int i = 0; i < cnts.size(); i++){
                if(cnts[i] == cnt){
                    return i;
                }
            }
            return -1;
        };
        for(const auto& str:strs){
            vector<int> temp_cnt(26, 0);
            for(const auto& c:str){
                temp_cnt[(int)(c - 'a')] += 1;
            }
            int idx = index_cnt(temp_cnt);
            if(idx != -1){
                res[idx].push_back(str);
            }
            else{
                cnts.push_back(temp_cnt);
                res.push_back(vector<string>(1, str));
            }
        }
        return res;
    }
};