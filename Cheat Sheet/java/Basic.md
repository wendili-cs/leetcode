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

## String相关
### String类
链接：https://www.runoob.com/java/java-string.html

```java
public class Main {
  public static void main(String[] args) {
    String s = "Aa Bb Cc Dd";
    System.out.println(s.charAt(1));
    System.out.println(s.length());
    String[] strs = s.split(" ");
    System.out.println(strs.length);
    System.out.println(strs[0]);
  }
}
```

输出：
```
a
11
4
Aa
```
### StringBuffer
链接：https://www.runoob.com/java/java-stringbuffer.html

```java
public class Main {
  public static void main(String[] args) {
    StringBuffer sBuffer = new StringBuffer("10=");
    sBuffer.append("1+");
    sBuffer.append("2+");
    sBuffer.append("3+4");
    System.out.println(sBuffer.toString());  
    // 反转
    sBuffer = sBuffer.reverse();
    sBuffer.insert(0, "Reverse: ");
    System.out.println(sBuffer);
  }
}
```

输出：
```
10=1+2+3+4
Reverse: 4+3+2+1=01
```