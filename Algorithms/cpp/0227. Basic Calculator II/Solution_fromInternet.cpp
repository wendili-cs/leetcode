// 【笔记】一般需要符号栈、数据栈，两个。但是，看到网上一个写的不错的算法，只用了一个数据栈。符号栈用一个变量sign代替了，只存储上一个符号，主要思想如下：
// 将减法转化为加法（取相反数）
// 由于乘除法优先级高，直接计算
// 整数不仅一位，会>10
// 表达式中没有括号
// 注意：
// 加减乘除空格的ASCII码都小于'0'，ASCII对照表如下：http://tool.oschina.net/commons?type=4
// 先做减法，避免int溢出
// char类型，不能使用switch
// 传送门：https://www.cnblogs.com/lightwindy/p/8686407.html

int calculate(string s) {
    int res = 0, d = 0;
    char sign = '+';
    stack<int> nums;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= '0') {//加减乘除和空格ASCII码都小于'0'
            d = d * 10 - '0' + s[i];//进位(先减法)
        }
        if ((s[i] < '0' && s[i] != ' ') || i == s.size() - 1) {
            if (sign == '+') {
                nums.push(d);
            } else if (sign == '-') {
                nums.push(-d);
            } else if (sign == '*' || sign == '/') {
                int tmp = sign == '*' ? nums.top() * d : nums.top() / d;
                nums.pop();
                nums.push(tmp);
            }
            sign = s[i]; //保存当前符号
            d = 0;
        }
    }
    for (; !nums.empty(); nums.pop()) {
        res += nums.top();
    }
    return res;
}