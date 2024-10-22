# 链表的操作

## 链表的定义代码
```c++
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
```

## 通过循环反转链表
```C++
ListNode *pre = head; // head是头链表，酌情加个空的假头
ListNode *cur = pre->next; // 注意：是从cur开始反转
ListNode *next;
for(int i = 0; i < right - left; i++){
    // 顶针地连续交换
    next = cur->next;
    cur->next = next->next;
    next->next = pre->next;
    pre->next = next;
}
```
