// https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int len = nums.size(), count = 0;
        vector<int> sorted(len);
        auto merge = [&](int l, int r, int mid) -> void {
            int l_ptr = l, r_ptr = mid + 1, cur_ptr = l;
            while(l_ptr <= mid && r_ptr <= r){
                if(nums[l_ptr] <= nums[r_ptr]){
                    sorted[cur_ptr] = nums[l_ptr];
                    count += r_ptr - mid - 1; // 当前的l_ptr大于[mid,mid+1,...,r_ptr-1]这些
                    l_ptr++;
                    cur_ptr++;
                }
                else{
                    sorted[cur_ptr] = nums[r_ptr];
                    r_ptr++;
                    cur_ptr++;
                }
            }
            while(l_ptr <= mid){
                sorted[cur_ptr] = nums[l_ptr];
                count += r_ptr - mid - 1;
                l_ptr++;
                cur_ptr++;
            }
            while(r_ptr <= r){
                sorted[cur_ptr] = nums[r_ptr];
                r_ptr++;
                cur_ptr++;
            }
            // for(int i = l; i <= r; i++){
            //     nums[i] = sorted[i];
            // }
            copy(&sorted[l], &sorted[r] + 1, &nums[l]); // 等价于前面的
        };

        function<void(int, int)> merge_sort;
        merge_sort = [&](int l, int r) -> void {
            if(l >= r) return;
            int mid = (l + r)/2;
            merge_sort(l, mid);
            merge_sort(mid + 1, r);
            merge(l, r, mid);
        };

        merge_sort(0, len - 1);
        return count;
    }
};