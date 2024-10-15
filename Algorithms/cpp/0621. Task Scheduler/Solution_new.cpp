// https://leetcode.com/problems/task-scheduler/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // cnter[c]: task c剩余的工作量
        unordered_map<char, int> cnter;
        for(char c:tasks){
            cnter[c]++;
        }
        
        int max_freq = 0; // 所有task中，最多的工作量是多少
        int max_task_count = 0; // 所有task中，有几个是最多的工作量
        for(auto it:cnter){
            if(max_freq < it.second){
                // 找到了更多工作量的task
                max_task_count = 1;
                max_freq = it.second;
            }
            else if(max_freq == it.second){
                // 找到了另一个最多工作量的task
                max_task_count++;
            }
        }

        // 计算有多少个idle：把最多工作量的tasks先按间隔n+1放入，再填入剩余的task，计算idle的数量
        // 比如n = 4, max_task_count = 2, max_freq = 5: (“.”表示空的，“|”表示放入的task)
        //     ||...||...||...||...||
        int chunk_count = max_freq - 1; // 植树原理，只算间隔
        int chunk_length = n + 1 - max_task_count; // 去掉已经放入的最多工作量的tasks
        int remaining_slots = chunk_count*chunk_length; // 剩余“.”的数量
        int remaining_tasks = tasks.size() - max_task_count*max_freq; // 剩余未放入的tasks
        int num_idles = max(0, remaining_slots - remaining_tasks); // 多少个slot是idle的
        return tasks.size() + num_idles;
    }
};