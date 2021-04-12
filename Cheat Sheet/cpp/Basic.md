# 这是Wendi写C++的Cheat Sheet

## for循环相关
### 迭代器

1. 想要拷贝元素：`for(auto each:range)`
2. 想要修改元素：`for(auto &&each:range)`
3. 想要只读元素：`for(const auto& each:range)`

## Hash相关
### unordered_map
相关链接：http://c.biancheng.net/view/7231.html

## vector相关
### 排序sort

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    sort(v.begin(), v.end());
    cout << "Sorted \n";
    for (auto x : v)
        cout << x << " ";
}
```