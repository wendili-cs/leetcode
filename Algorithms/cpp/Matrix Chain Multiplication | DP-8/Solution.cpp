// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

// Input: arr[] = {40, 20, 30, 10, 30}
// Output: 26000
// Explanation:There are 4 matrices of dimensions 40×20, 20×30, 30×10, 10×30.
// Let the input 4 matrices be A, B, C and D.
// The minimum number of  multiplications are obtained by 
// putting parenthesis in following way (A(BC))D.
// The minimum is 20*30*10 + 40*20*10 + 40*10*30

// Input: arr[] = {1, 2, 3, 4, 3}
// Output: 30
// Explanation: There are 4 matrices of dimensions 1×2, 2×3, 3×4, 4×3. 
// Let the input 4 matrices be A, B, C and D.  
// The minimum number of multiplications are obtained by 
// putting parenthesis in following way ((AB)C)D.
// The minimum number is 1*2*3 + 1*3*4 + 1*4*3 = 30

// Input: arr[] = {10, 20, 30}
// Output: 6000  
// Explanation: There are only two matrices of dimensions 10×20 and 20×30. 
// So there  is only one way to multiply the matrices, cost of which is 10*20*30


int getMatrixChain(vector <int> p) {
    int n = p.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    function<int(int, int)> recur;
    recur = [&](int x, int y) -> int {
        // min operations for range whose indices are in [x, y)
        if(x == y) return 0;
        if(dp[x][y] == -1){
            int ret = INT_MAX;
            for(int i = x; i < y; i++){
                ret = min(ret, recur(x, i) + recur(i + 1, y) + p[x - 1]*p[i]*p[y]);
            }
            dp[x][y] = ret;
        }
        return dp[x][y];
    };
    return recur(1, n - 1);
}