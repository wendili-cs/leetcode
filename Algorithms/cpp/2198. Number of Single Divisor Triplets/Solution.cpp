// https://leetcode.com/problems/number-of-single-divisor-triplets/

class Solution {
public:
    long long singleDivisorTriplet(vector<int>& nums) {
        long res = 0;
        map<int, long> cnt;
        for(int& num:nums) cnt[num]++;
        for(auto it1 = cnt.begin(); it1 != cnt.end(); it1++){
            for(auto it2 = it1; it2 != cnt.end(); it2++){
                for(auto it3 = it2; it3 != cnt.end(); it3++){
                    int cur = 0;
                    if((it1->first + it2->first)%it3->first == 0) cur++;
                    if((it1->first + it3->first)%it2->first == 0) cur++;
                    if((it2->first + it3->first)%it1->first == 0) cur++;
                    if(cur == 1){
                        if(it1 == it2 || it2 == it3){
                            res += 3*it1->second*(it2->second - 1)*it3->second;
                        }
                        else{
                            res += 6*it1->second*it2->second*it3->second;
                        }
                    }
                }
            }
        }
        return res;
        
    }
};