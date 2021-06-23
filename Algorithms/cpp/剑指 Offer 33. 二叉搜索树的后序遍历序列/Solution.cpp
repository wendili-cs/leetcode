// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        function<bool(int, int)> recur;
        recur = [&](int l, int r) -> bool {
            if(l >= r) return true;
            int split;
            for(split = l; postorder[split] < postorder[r]; split++);
            for(int i = split; i < r; i++) if(postorder[i] < postorder[r]) return false;
            if(!recur(l, split - 1)||!recur(split, r - 1)) return false;
            return true;
        };
        return recur(0, postorder.size() - 1);
    }
};