// https://leetcode-cn.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/

// 要点：
// 1. 算异或累积和，S[i+1] = S[i]^x[i]，由于异或的自反性，可以得到若S[i]==S[k+1]==S[k]^x[i]，则对于(i, k+1)之间任意j，都满足题意，所以可以双重循环。
// 2. 可以进一步用hash来实现O(n)时间复杂度
//     2.1 对于k，若i1, i2, ..., im都满足S[k]^x[i]==S[k+1]==S[i]，则这些二元组对答案的贡献和：(k-i1)+...+(k-im)=m*k-sum([ix for x in range(m)])
//     2.2 所以对于S[i]==S[k+1]，则需要记录i的出现次数以及下标之和。res += cnter + isum

// O(n^2)的双重循环
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int len = arr.size(), res = 0;
        vector<int> S(len + 1, 0);
        for(int i = 0; i < len; i++) S[i + 1] = S[i]^arr[i];
        for(int i = 0; i < len; i++){
            for(int k = i + 1; k < len; k++){
                if(S[i] == S[k + 1])
                    res += k - i;
            }
        }
        return res;
    }
};

// O(n)的hash
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int len = arr.size(), res = 0;
        vector<int> S(len + 1, 0); // 其实可以写成一个int
        unordered_map<int, int> cnter, isum;
        for(int k = 0; k < len; k++){
            S[k + 1] = S[k]^arr[k];
            res += cnter[S[k + 1]]*k - isum[S[k + 1]];
            cnter[S[k]]++; // !!：S[k]是类似于base的，从S[i-1](base)-->S[j]-->S[k](base)是原地踏步，所以cnt和isum的key是S[k]而不是S[k+1]
            isum[S[k]] += k;
        }
        return res;
    }
};