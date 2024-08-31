// https://www.geeksforgeeks.org/how-to-check-if-a-given-array-represents-a-binary-heap/

bool isMaxHeap(vector<int>& nums) {
    int n = nums.size();
    function<bool(int)> recur;
    recur = [&](int x) -> bool {
        if(x >= n) return true;
        if(recur(2*x + 1) && recur(2*x + 2)){
            if((2*x + 1 >= n || nums[x] >= nums[2*x + 1]) && (2*x + 2 >= n || nums[x] >= nums[2*x + 2])){
                return true;
            }
        }
        return false;
    };
    return recur(0);
}