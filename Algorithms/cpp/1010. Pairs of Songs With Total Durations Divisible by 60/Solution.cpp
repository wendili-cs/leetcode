// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        map<int, int>m;
        for(int& each:time) m[each]++;
        for(int i = 1; 60*i <= 1000; i++){
            for(auto it:m){
                if(it.first <= 60*i/2 && m.find(60*i - it.first) != m.end()){
                    if(60*i - it.first == it.first){
                        res += it.second*(it.second-1)/2;
                    }
                    else{
                        res += m[60*i - it.first]*it.second;
                    }
                }
            }
        }
        return res;
    }
};