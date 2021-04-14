# 这是Wendi写C++的Cheat Sheet

## 1. for循环相关
### 迭代器

1. 想要拷贝元素：`for(auto each:range)`
2. 想要修改元素：`for(auto &&each:range)`
3. 想要只读元素：`for(const auto& each:range)`

## 2. Hash相关
### unordered_map
相关链接：http://c.biancheng.net/view/7231.html

## 3. vector相关
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

## 4. C++关键字
### decltype
相关链接：https://www.cnblogs.com/cauchy007/p/4966485.html

意义：从表达式的类型推断出要定义的变量类型，但是不想用该表达式的值初始化变量（如果要初始化就用auto了）。为了满足这一需求，C++11新标准引入了decltype类型说明符，它的作用是选择并返回操作数的数据类型，在此过程中，编译器分析表达式并得到它的类型，却不实际计算表达式的值。

```c++
int getSize();

int main(void)
{
    int tempA = 2;
    /*1.dclTempA为int*/
    decltype(tempA) dclTempA;
    /*2.dclTempB为int，对于getSize根本没有定义，但是程序依旧正常，因为decltype只做分析，并不调用getSize，*/
    decltype(getSize()) dclTempB;
}
```

## 5. 函数相关
### lambda函数
相关链接：https://www.cnblogs.com/jimodetiantang/p/9016826.html

lambda的语法形式：
```
[函数对象参数] (操作符重载函数参数) mutable 或 exception 声明 -> 返回值类型 {函数体}
```

函数对象参数可以的选项
* 空 ：没有任何函数对象参数。
* `=` ：函数体内可以使用 Lambda 所在范围内所有可见的局部变量（包括 Lambda 所在类的 this），并且是值传递方式（相当于编译器自动为我们按值传递了所有局部变量）。
* `&` ：函数体内可以使用 Lambda 所在范围内所有可见的局部变量（包括 Lambda 所在类的 this），并且是引用传递方式（相当于是编译器自动为我们按引用传递了所有局部变量）。
* `this` ：函数体内可以使用 Lambda 所在类中的成员变量。
* `a` ：将 a 按值进行传递。按值进行传递时，函数体内不能修改传递进来的 a 的拷贝，因为默认情况下函数是 const 的，要修改传递进来的拷贝，可以添加 mutable 修饰符。
* `&a` ：将 a 按引用进行传递。
* `a，&b` ：将 a 按值传递，b 按引用进行传递。
* `=，&a，&b` ：除 a 和 b 按引用进行传递外，其他参数都按值进行传递。
* `&，a，b` ：除 a 和 b 按值进行传递外，其他参数都按引用进行传递。

例如：
```c++
int main() {
	int t = 10;
	int x = 22, y = 33;
	cout << "Init x: " << x << ", y: " << y << endl;
	//cin >> x >> y;
	auto f1 = [=](int x, int y) {return x + y + t; };
	auto f2 = [](int& x) {++x;};
	auto f3 = [](int x) {++x; };
	auto f4 = [](int x, int y) -> int { int z = x + y; return z; };
	cout << "f1:" << f1(x, y) << endl;
	f2(x);
	f3(x);
	cout << "After f2, x: " << x << endl;
	cout << "f4:" << f4(x, y) << endl;
	system("pause");
}
```
输出：
```
Init x: 22, y: 33
f1:65
After f2, x: 23
f4:56
```

Lambda 函数是一个依赖于实现的函数对象类型,这个类型的名字只有编译器知道. 如果用户想把 lambda 函数做为一个参数来传递, 那么形参的类型必须是模板类型或者必须能创建一个 std::function 类似的对象去捕获 lambda 函数.使用 auto 关键字可以帮助存储 lambda 函数,

```c++
auto my_lambda_func = [&](int x) { /* ... */ };
auto my_onheap_lambda_func = new auto([=](int x) { /* ... */ });

auto a_lambda_func = [](int x) { /* ... */ };
void (*func_ptr)(int) = a_lambda_func;
func_ptr(4); // calls the lambda
```

```c++
double eval(function<double(double)> f, double x = 2.0) { return f(x); };

int main() {
	function<double(double)> f0 = [](double x) {return 1; };
	auto f1 = [](double x) {return x; };
	decltype(f0) f_arr[3] = { f0, f1, [](double x) {return x * x; } };
	for (auto f : f_arr) {
		cout << f(2.0) << endl;
	}
	system("pause");
}
```

### min_element、max_element函数

```c++
int main()
{
	vector<int>v = { 1,5,8,2,4,6,7,3 };
	cout << *min_element(v.begin(), v.end()) << endl;
	cout << *max_element(v.begin(), v.end()) << endl;
	system("pause");
}
```