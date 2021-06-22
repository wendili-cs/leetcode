# 链表的操作

## 通过循环反转链表
```C++
ListNode *pre = head; // head是头链表，酌情加个空的假头
ListNode *cur = pre->next;
ListNode *next;
for(int i = 0; i < right - left; i++){
    // 顶针地连续交换
    next = cur->next;
    cur->next = next->next;
    next->next = pre->next;
    pre->next = next;
}
```
