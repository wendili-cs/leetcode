// https://leetcode-cn.com/problems/rabbits-in-forest/
// 对于n个兔子说有m个的情况：
// 1. m == 0，则这n个要单独算；
// 2. n <= m + 1，则这些考虑为同一种颜色，总数量+(m+1)个
// 3. n > m + 1，则会有不同类的，最多每(m+1)个兔子是一种颜色，所以总数量+((n-1)/(m+1)+1)*(m+1)个
// 其实1和2是3的特殊情况

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> umap;
        for(const int& ans:answers){
            umap[ans]++;
        }
        int sum = 0;
        for(auto iter = umap.begin(); iter != umap.end(); iter++){
            sum += (iter->first + 1) * ((iter->second - 1)/(iter->first + 1) + 1);
        }
        return sum;
    }
};