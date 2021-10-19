// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> n2f;
        set<pair<int,int>> f2n;
        for(int& num:arr) n2f[num]++;
        for(auto it:n2f){
            f2n.emplace(it.second, it.first);
        }
        while(k > 0){
            if(k < (f2n.begin()->first)){
                break;
            }
            k -= f2n.begin()->first;
            f2n.erase(f2n.begin());
        }
        return f2n.size();
    }
};