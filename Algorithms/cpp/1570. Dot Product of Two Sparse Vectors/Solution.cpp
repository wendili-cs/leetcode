// https://leetcode.com/problems/dot-product-of-two-sparse-vectors/

class SparseVector {
public:
    map<int, int> mp;
    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0) mp[i] = nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        auto it1 = vec.mp.begin(), it2 = mp.begin();
        while(it1 != vec.mp.end() && it2 != mp.end()){
            if(it1->first < it2->first) it1++;
            else if(it1->first > it2->first) it2++;
            else{
                res += it1->second * it2->second;
                it1++;
                it2++;
            }
        }
        return res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);