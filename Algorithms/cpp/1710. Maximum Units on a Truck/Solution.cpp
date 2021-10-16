// https://leetcode.com/problems/maximum-units-on-a-truck/

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        map<int, int>m;
        for(auto& box:boxTypes){
            m[-box[1]] = m[-box[1]] + box[0];
        }
        int res = 0;
        for(auto it:m){
            if(truckSize >= it.second){
                res += -it.first*it.second;
                truckSize -= it.second;
            }
            else{
                res += -it.first*truckSize;
                break;
            }
        }
        return res;
    }
};