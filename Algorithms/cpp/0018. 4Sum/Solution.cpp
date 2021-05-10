// https://leetcode-cn.com/problems/4sum/

struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_set<vector<int>, VectorHash> uset;
        vector<vector<int> > res;
        int len = nums.size(), l, r;
        sort(nums.begin(), nums.end());
        for(int  i = 0; i < len - 3; i++){
            for(int j = i + 1; j < len - 2; j++){
                int two_sum = target - nums[i] - nums[j];
                l = j + 1, r = len - 1;
                while(l < r){
                    int l_r_sum = nums[l] + nums[r];
                    if(l_r_sum == two_sum){
                        vector<int> temp = {nums[i], nums[j], nums[l], nums[r]};
                        uset.insert(temp);
                        l++;
                        r--;
                    }
                    else if(l_r_sum < two_sum) l++;
                    else r--;
                }
            }
        }
        for(auto iter = uset.begin(); iter != uset.end(); iter++){
            res.push_back(*iter);
        }
        return res;
    }
};