// https://leetcode.com/problems/prime-arrangements/

class Solution {
public:
    int numPrimeArrangements(int n) {
        auto is_prime = [](int x) -> bool {
            if(x == 2) return true;
            for(int i = 2; i * i <= x; i++){
                if(x % i == 0) return false;
            }
            return true;
        };
        long p = 0, np = 1, M = 1000000007, res = 1;
        // final would be A_m^m * A_n^n, where m is # of primes, n is # of composites
        for(int x = 2; x <= n; x++){
            if(is_prime(x)) {
                p++;
                res = (res * p) % M;
            }
            else {
                np++;
                res = (res * np) % M;
            }
        }
        return res;
    }
};