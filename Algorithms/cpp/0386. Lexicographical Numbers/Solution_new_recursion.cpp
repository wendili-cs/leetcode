// https://leetcode.com/problems/lexicographical-numbers/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        function<void(int)> recur;
        recur = [&](int i) -> void {
            if(i > n) return;
            res.push_back(i);
            recur(i*10); // first expand by multiplying 10
            if((i + 1)%10 != 0) recur(i + 1); // second expand by adding 10
        };
        recur(1);
        return res;
    }
};