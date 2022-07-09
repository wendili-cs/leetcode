// https://leetcode.com/problems/intervals-between-identical-elements/

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, long> mp, mp2, cnt, cnt2;
        for(int i = 0; i < n; i++){
            mp[arr[i]] += i;
            cnt[arr[i]]++;
        }
        vector<long long> res(n, 0);
        for(int i = 0; i < n; i++){
            if(mp.find(arr[i]) != mp.end()){
                res[i] = mp[arr[i]] - 2*mp2[arr[i]] - (cnt[arr[i]] - 2*cnt2[arr[i]])*i;
            }
            mp2[arr[i]] += i;
            cnt2[arr[i]]++;
        }
        return res;
    }
};