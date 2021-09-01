// https://leetcode-cn.com/problems/reorder-data-in-log-files/

class Solution {
public:
    static bool cmp(string& a, string& b) {
        int i = a.find(' '), j = b.find(' ');
        string ax = a.substr(i + 1), bx = b.substr(j + 1);
        if(ax == bx) return a < b;
        return ax < bx;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        int size = logs.size();
        for(int i = 0; i < size; i++){
            if(isdigit(logs[i].back())){
                rotate(logs.begin() + i, logs.begin() + i + 1, logs.end());
                size--;
                i--;
            }
        }
        sort(logs.begin(), logs.begin() + size, cmp);
        return logs;
    }
};