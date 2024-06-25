## String Steam用法

[来源链接](https://www.cnblogs.com/narjaja/p/10044157.html)

### 默认分割空格、tab、回车换行：
```c++
int main() {
    string str = "hello world sperated by   spaces\tand\nhuiche";
 
    vector<string> arr;
    istringstream ss(str);
    string word;
    while(ss>>word) {
        arr.push_back(word);
    }
 
    for(size_t i=0; i<arr.size(); i++) {
        cout << arr[i] << endl;
    }
     
    return 0;
}
```

### 利用指定字符分割字符串
```c++
int main() {
        string data = "1_2_3_4_5_6";
        stringstream ss(data);
        string item;
        cout << data << endl;
        while (getline(ss, item, '_')) 
            cout << item << ' ';  
}

//1_2_3_4_5_6
//1 2 3 4 5 6 
```