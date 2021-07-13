// https://leetcode-cn.com/problems/task-scheduler/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnter(26, 0);
        for(auto& task:tasks) cnter[task - 'A']++;
        sort(cnter.begin(), cnter.end());
        int len = tasks.size(), max_freq_tasks = 0; // 出现频率最高的task有几个
        for(int i = 25; i >= 0; i--){
            if(cnter[i] != cnter.back()) break;
            max_freq_tasks++;
        }
        return max(len, (n + 1)*(cnter.back() - 1) + max_freq_tasks);
    }
};