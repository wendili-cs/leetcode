# 并查集
## 并查集的代码
```c++
// 初始化
vector<int> dset(n);
for(int i = 0; i < n; i++) dset[i] = i;

// 并查集的查找函数
function<int(int)> find;
find = [&](int x) -> int {
    if(dset[x] != x) dset[x] = find(dset[x]);
    return dset[x];
};

// 使用方式
for(auto& edge:edges){
    dset[find(edge[0])] = find(edge[1]);
}
```