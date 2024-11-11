// https://leetcode.com/problems/prime-subtraction-operation/

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int maxp = 1000; // 定义数据范围
        vector<bool> isPrime(maxp + 1, true); 
        isPrime[0] = isPrime[1] = false;
        // 素数筛
        for(int i = 2; i*i <= maxp; i++){
            if(isPrime[i]){
                for(int j = i*i; j <= maxp; j += i){
                    isPrime[j] = false;
                }
            }
        }
        vector<int> primes;
        for(int i = 2; i <= maxp; i++){
            if(isPrime[i]) primes.push_back(i); // 最后我们得到了直到1000为止的所有素数
        }
        for(int i = nums.size() - 1; i > 0; i--){
            if(nums[i - 1] >= nums[i]){
                int min_diff = nums[i - 1] - nums[i] + 1; // 要严格递增
                auto it = lower_bound(primes.begin(), primes.end(), min_diff);
                if(it == primes.end() || *it >= nums[i - 1]) return false; // 找不到严格小于nums[i-1]的质数
                nums[i - 1] -= *it;
            }
        }
        return true;
    }
};