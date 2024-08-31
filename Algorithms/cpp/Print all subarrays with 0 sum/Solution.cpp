// https://www.geeksforgeeks.org/print-all-subarrays-with-0-sum/

vector<vector<int>> findSubArrays(vector<int>& nums) {
    vector<vector<int>> res;
    unordered_map<int, vector<int>> mp;
    mp[0].push_back(0);
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        if(mp.find(sum) != mp.end()){
            for(int start:mp[sum]){
                res.push_back({start, i});
            }
        }
        mp[sum].push_back(i + 1);
    }
    sort(res.begin(), res.end());
    return res;
}