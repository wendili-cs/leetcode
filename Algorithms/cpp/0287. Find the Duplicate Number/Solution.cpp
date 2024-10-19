// https://leetcode-cn.com/problems/find-the-duplicate-number/
// https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        while(true){
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(slow == fast){ // 这个瞬间，它离开始点0和slow的点的距离一定是相等的，所以相遇点就是环的起始点
                fast = 0;
                while(slow != fast){
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
        }
    }
};

// 另一个binary search的方法，复杂度O(NlogN)，不是最优解
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 二分查找：每次找那个多出来的元素是在[left, mid]区间还是(mid, right]区间，直到找出那个元素
        int left = 1, right = nums.size() - 1; // 因为数字范围是[1, n]
        while(left < right){
            int mid = left + (right - left)/2, cnt = 0;
            for(int num:nums){
                if(num <= mid){
                    cnt++;
                }
            }
            // 更新left和right
            if(cnt > mid){ // 在[left, mid]区间
                right = mid;
            }
            else{ // 在(mid, right] 区间，所以mid + 1
                left = mid + 1;
            }
        }
        return left;
    }
};