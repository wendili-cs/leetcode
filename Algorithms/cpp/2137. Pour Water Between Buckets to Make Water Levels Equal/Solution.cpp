// https://leetcode.com/problems/pour-water-between-buckets-to-make-water-levels-equal/

class Solution {
public:
    double equalizeWater(vector<int>& buckets, int loss) {
        double l = 0.0, r = 100000.0, mid, rem, prec = 0.000001;
        while(l < r - prec){
            mid = (r + l)/2, rem = 0.0;
            for(int &num:buckets){
                if(num > mid){
                    rem += (num - mid)*(100 - loss)/100;
                }
                else{
                    rem -= mid - num;
                }
            }
            if(-prec <= rem && rem <= prec){
                break;
            }
            else if(rem < -prec){
                r = mid - prec;
            }
            else{
                l = mid + prec;
            }
        }
        return mid;
    }
};