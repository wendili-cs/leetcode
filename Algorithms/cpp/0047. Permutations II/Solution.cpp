// https://leetcode-cn.com/problems/permutations-ii/

// 注意：递归的时候传递的是参数，numc是执行时nums的copy副本！
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        function<void(vector<int>, int)> recur;
        recur = [&](vector<int> numc, int l) -> void {
            if(l == numc.size() - 1){
                res.push_back(numc);
                return;
            }
            for(int i = l; i < numc.size(); i++){
                if(i != l && numc[i] == numc[l]) continue;
                swap(numc[i], numc[l]);
                recur(numc, l + 1);
            }
        };
        recur(nums, 0);
        return res;
    }
};