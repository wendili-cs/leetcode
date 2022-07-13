// https://leetcode.com/problems/number-of-unique-flavors-after-sharing-k-candies/

class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < candies.size(); i++){
            mp[candies[i]]++;
        }
        int size = mp.size(), cur = 0;
        for(int i = 0; i < k; i++){
            if(mp[candies[i]] > 1) mp[candies[i]]--;
            else mp.erase(candies[i]);
        }
        cur = mp.size();
        for(int i = k; i < candies.size(); i++){
            mp[candies[i - k]]++;
            if(mp[candies[i]] > 1){
                mp[candies[i]]--;
            }
            else{
                mp.erase(candies[i]);
            }
            cur = cur > mp.size()? cur:mp.size();
        }
        return cur;
    }
};