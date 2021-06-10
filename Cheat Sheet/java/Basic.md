# 这是Wendi写Java的Cheat Sheet

## 数组相关
### 数组
推荐使用``type[] arrayName``的形式。
```java
// 声明、分配空间、赋值
int[] intArray = {1, 2, 3};
// 显式初始化
boolean[] boolArray;
boolArray = new boolean[]{true, false, true};
```

### ArrayList类
位于``java.util``包中，需要import
```java
import java.util.ArrayList;

public class Test {
    public static void main(String[] args) {
        ArrayList<Integer> sites = new ArrayList<Integer>();
        sites.add(1);
        System.out.println(sites);
    }
}
```