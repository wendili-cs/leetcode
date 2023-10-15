// https://leetcode.com/contest/weekly-contest-367/problems/find-indices-with-index-and-value-difference-ii/

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        multiset<int> s;
        map<int, multiset<int>::iterator> i2v; // index to iterator
        // map<multiset<int>::iterator, int> v2i; // iterator to index
        for(int i = 0; i < nums.size(); i ++){
            i2v[i] = s.insert(nums[i]);
            // v2i[i2v[i]] = i;
        }
        if(indexDifference == 0 && valueDifference == 0) return {0, 0};
        if(indexDifference == 0) indexDifference = 1;
        int l = -indexDifference + 1, ilen = max(1, 2*indexDifference - 1), len = nums.size(); // r = l + ilen - 1
        vector<int> res = {-1, -1};
        auto try_remove = [&](int idx) -> void {
            if(0 <= idx && idx < len){
                if(i2v.find(idx) != i2v.end()){
                    s.erase(i2v[idx]);
                    // v2i.erase(i2v[idx]);
                    i2v.erase(idx);
                }
            }
        };
        
        auto try_add = [&](int idx) -> void {
            if(0 <= idx && idx < len){
                if(i2v.find(idx) == i2v.end()){
                    i2v[idx] = s.insert(nums[idx]);
                    // v2i[i2v[idx]] = idx;
                }
            }
        };
        
        auto find_index = [&](multiset<int>::iterator tit) -> int {
            auto it = i2v.begin();
            while(it != i2v.end()){
                if(it->second == tit) {
                    return it->first;
                }
                it++;
            }
            return -1;
        };
        
        for(int i = l; i < l + ilen; i++){
            try_remove(i); // erase index from [l, r]
        }

        for(int i = 0; i < len; i++){
            if(i != 0 && ilen > 1){
                l++;
                int r = l + ilen - 1;
                try_remove(r);
                try_add(l - 1);
                
            }
            if(s.empty()) continue;
            if(abs(nums[i] - *(s.begin())) >= valueDifference){
                res[0] = find_index(s.begin());
                res[1] = i;
                sort(res.begin(), res.end());
                return res;
            }
            if(abs(nums[i] - *(s.rbegin())) >= valueDifference){
                auto it = s.end();
                it--;
                res[0] = find_index(it);
                res[1] = i;
                sort(res.begin(), res.end());
                return res;
            }
        }
        return res;
    }
};