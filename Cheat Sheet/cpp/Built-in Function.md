## min_element、max_element函数

```c++
int main()
{
	vector<int>v = { 1,5,8,2,4,6,7,3 };
	cout << *min_element(v.begin(), v.end()) << endl;
	cout << *max_element(v.begin(), v.end()) << endl;
	system("pause");
}
```

来自LeetCode `621. Task Scheduler` 中的代码：
```c++
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char ch: tasks) {
            ++freq[ch];
        }

        // 最多的执行次数
        int maxExec = max_element(freq.begin(), freq.end(), [](const auto& u, const auto& v) {
            return u.second < v.second;
        })->second;
        // 具有最多执行次数的任务数量
        int maxCount = accumulate(freq.begin(), freq.end(), 0, [=](int acc, const auto& u) {
            return acc + (u.second == maxExec);
        });

        return max((maxExec - 1) * (n + 1) + maxCount, static_cast<int>(tasks.size()));
    }
};
```
