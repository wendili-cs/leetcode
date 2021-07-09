## priority_queue优先队列
链接：https://blog.csdn.net/weixin_36888577/article/details/79937886

```c++
int main()
{
	// 对于基础类型 默认是大顶堆
	priority_queue<int> a;
	// 等同于 priority_queue<int, vector<int>, less<int> > a;
	priority_queue<int, vector<int>, greater<int> > c;  // 这样就是小顶堆
	priority_queue<string> b;

	for (int i = 0; i < 5; i++){
		a.push(i);
		c.push(i);
	}
	while (!a.empty()){
		cout << a.top() << ' ';
		a.pop();
	}
	cout << endl;

	while (!c.empty()){
		cout << c.top() << ' ';
		c.pop();
	}
	cout << endl;

	b.push("abc");
	b.push("abcd");
	b.push("cbd");
	while (!b.empty()){
		cout << b.top() << ' ';
		b.pop();
	}
	cout << endl;
	system("pause");
}
```

输出：
```
4 3 2 1 0
0 1 2 3 4
cbd abcd abc
```

### Priority queue的比较方法重载（代码）
[原文链接](https://blog.csdn.net/weixin_36888577/article/details/79937886)
```c++
#include <iostream>
#include <queue>
using namespace std;

//方法1
struct tmp1 //运算符重载<
{
    int x;
    tmp1(int a) {x = a;}
    bool operator<(const tmp1& a) const
    {
        return x < a.x; //大顶堆
    }
};

//方法2
struct tmp2 //重写仿函数
{
    bool operator() (tmp1 a, tmp1 b) 
    {
        return a.x < b.x; //大顶堆
    }
};

int main() 
{
    tmp1 a(1);
    tmp1 b(2);
    tmp1 c(3);
    priority_queue<tmp1> d;
    d.push(b);
    d.push(c);
    d.push(a);
    while (!d.empty()) 
    {
        cout << d.top().x << '\n';
        d.pop();
    }
    cout << endl;

    priority_queue<tmp1, vector<tmp1>, tmp2> f;
    f.push(c);
    f.push(b);
    f.push(a);
    while (!f.empty()) 
    {
        cout << f.top().x << '\n';
        f.pop();
    }
}
```