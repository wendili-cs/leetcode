# 这是Wendi写C++的Cheat Sheet

## 1. for循环相关
### 迭代器

1. 想要拷贝元素：`for(auto each:range)`
2. 想要修改元素：`for(auto& each:range)`
3. 想要只读元素：`for(const auto& each:range)`

## 2. Hash相关
### unordered_map
相关链接：http://c.biancheng.net/view/7231.html

示例：
```c++
int main() {
	string s = "abcabcbb";
	unordered_map<char, int> dict;
	for (const auto& word : s) {
		auto iter = dict.find(word);
		if (iter != dict.end()) {
			iter->second += 1;
		}
		else {
			dict.emplace(word, 0);
		}
	}
	for (auto iter = dict.begin(); iter != dict.end(); iter++) {
		cout << iter->first << " " << iter->second;
		cout << endl;
	}
}
```


### unordered_set
相关链接：
* http://c.biancheng.net/view/7250.html
* https://blog.csdn.net/zhang14916/article/details/100859487

示例：
```c++
int main() {
	string s = "abcabcbb";
	unordered_set<char> uset;
	for (const auto& word : s) {
		auto iter = uset.find(word);
		if (iter == uset.end()) {
			uset.emplace(word);
		}
	}
	uset.erase('a');
	for (auto iter = uset.begin(); iter != uset.end(); iter++) {
		cout << *iter << endl;
	}
	cout << uset.size() << endl;
}
```

## 3. vector相关
### 排序sort

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const int& num1, const int& num2) {
	return num1 > num2;
}

int main()
{
    vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    sort(v.begin(), v.end());
	// sort(v.begin(), v.end(), cmp); // 如果用这个则是降序排列
    cout << "Sorted \n";
    for (auto x : v)
        cout << x << " ";
}
```
输出：
```
Sorted
0 1 2 3 4 5 6 7 8 9
```

### vector初始化
链接：https://www.jianshu.com/p/d058866e0e10

1. `1.vector<int> list1; // 默认初始化，最常用`
2. `vector<int> list2(list);` or `vector<int> ilist2 = ilist;`
3. `vector<int> list = {1,2,3};`
4. `vector<int> list3(list.begin()+2, list.end()-1);`
5. `vector<int> ilist4(7); // 定义其长度为7`
6. `vector<int> ilist5(7,3); // 定义其长度为7，初始值为3`

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

#### lambda的语法形式：
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

#### 捕获lambda函数
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

#### lambda函数用于递归
两种方式：
1. 引入self
```c++
auto factorial = [](auto&& self, int n) -> int { return n < 2 ? 1 : n * self(self, n - 1); };
```
2. 先声明再赋值
```c++
std::function<int(int)> factorial;
factorial = [&factorial](int n) { return n < 2 ? 1 : n * factorial(n - 1); }；
```

## 6. 一些属性、结构体
### 最大值
内置最大值的宏定义：https://blog.csdn.net/caroline_wendy/article/details/24311895

### pair函数
链接：https://blog.csdn.net/sevenjoin/article/details/81937695

pair是将2个数据组合成一组数据，其标准库类型--pair类型定义在#include <utility>头文件中，定义如下：

类模板：`template<class T1,class T2> struct pair`

参数：T1是第一个值的数据类型，T2是第二个值的数据类型。

```c++
pair<T1, T2> p1; //创建一个空的pair对象（使用默认构造），它的两个元素分别是T1和T2类型，采用值初始化。
pair<T1, T2> p1(v1, v2); //创建一个pair对象，它的两个元素分别是T1和T2类型，其中first成员初始化为v1，second成员初始化为v2。
make_pair(v1, v2); // 以v1和v2的值创建一个新的pair对象，其元素类型分别是v1和v2的类型。
p1 < p2; // 两个pair对象间的小于运算，其定义遵循字典次序：如 p1.first < p2.first 或者 !(p2.first < p1.first) && (p1.second < p2.second) 则返回true。
p1 == p2; // 如果两个对象的first和second依次相等，则这两个对象相等；该运算使用元素的==操作符。
p1.first; // 返回对象p1中名为first的公有数据成员
p1.second; // 返回对象p1中名为second的公有数据成员
```

### 堆栈队列相关
#### priority_queue优先队列
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

#### stack栈
相关链接：http://c.biancheng.net/view/478.html
和其他序列容器相比，stack 是一类存储机制简单、所提供操作较少的容器。下面是 stack 容器可以提供的一套完整操作：
* top()：返回一个栈顶元素的引用，类型为 T&。如果栈为空，返回值未定义。
* push(const T& obj)：可以将对象副本压入栈顶。这是通过调用底层容器的 push_back() 函数完成的。
* push(T&& obj)：以移动对象的方式将对象压入栈顶。这是通过调用底层容器的有右值引用参数的 push_back() 函数完成的。
* pop()：弹出栈顶元素。
* size()：返回栈中元素的个数。
* empty()：在栈中没有元素的情况下返回 true。
* emplace()：用传入的参数调用构造函数，在栈顶生成对象。
* swap(stack<T> & other_stack)：将当前栈中的元素和参数中的元素交换。参数所包含元素的类型必须和当前栈的相同。对于 stack 对象有一个特例化的全局函数 swap() 可以使用。

### lower_bound函数
`lower_bound()` 函数用于在指定区域内查找不小于目标值的第一个元素。也就是说，使用该函数在指定范围内查找某个目标值时，最终查找到的不一定是和目标值相等的元素，还可能是比目标值大的元素。
```c++
int main()
{
	int a[5] = { 1,2,4,3,5 };
	//从 a 数组中找到第一个不小于 3 的元素
	int *p = lower_bound(a, a + 5, 3);
	cout << "*p = " << *p << endl;
}
```

### &运算

链接：https://blog.csdn.net/weixin_45774972/article/details/115013711

* `n&1`：判断`n`是否为奇数。因为n为奇数时，对应的二进制数最低位一定为1，n&1的结果就是1；n为偶数时，相应的最低位为0，n&1的结果就是0。
* `1&n`：检查二进制`n`的最低位，若为1，则1&n的结果就是1；若不为1，则1&n的结果就是0。
* `n&-n`：当一个数与其取负后的值相与， 如果这个数是偶数， 则结果是能整除这个偶数的最大的2的幂(即： `m = n & -n` , 则 `n % m = 0`, 且 `m = 2 ^ k`)， 如果这个数是奇数， 则结果必为1。用途： 一般可以用来获取某个二进制数的LowBit。

### 取rank（数字在数组中依据大小的排序）
```c++
// 将数组转换成rank
void get_rank(vector<int>& nums){
	int len = nums.size();
	vector<int> temp = nums;
	sort(temp.begin(), temp.end());
	for(int &num:nums){
		num = lower_bound(temp.begin(), temp.end(), num) - temp.begin() + 1;
	}
}
```
