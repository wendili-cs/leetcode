## Dijkstra算法
[链接](https://blog.csdn.net/YF_Li123/article/details/74090301)

伪代码：
```C++
//G为图；数组d为源点到达各点的最短路径长度，s为起点
Dijkstra(G, d[], s)
{
     初始化;
     for(循环n次)
     {
          u = 使d[u]最小的还未被访问的顶点的标号;
          记u已被访问;
          for(从u出发能到达的所有顶点v)
          {
               if(v未被访问 && 以u为中介点使s到顶点v的最短距离d[v]更优)
               {
                    优化d[v];
               }
          }
     }
}
```

邻接矩阵版：
```C++
const int INF = 1000000000;
 
/*Dijkstra算法解决的是单源最短路径问题，即给定图G(V,E)和起点s(起点又称为源点),
求从起点s到达其它顶点的最短距离，并将最短距离存储在矩阵d中*/
void Dijkstra(int n, int s, vector<vector<int>> G, vector<bool>& vis, vector<int>& d)
{
       /*
       param
       n：           顶点个数
       s：           源点
       G：           图的邻接矩阵
       vis：         标记顶点是否已被访问
       d：           存储源点s到达其它顶点的最短距离
       */
       fill(d.begin(), d.end(), INF);                         //初始化最短距离矩阵，全部为INF
       d[s] = 0;                                              //起点s到达自身的距离为0
       for (int i = 0; i < n; ++i)
       {
              int u = -1;                                     //找到d[u]最小的u
              int MIN = INF;                                  //记录最小的d[u]
              for (int j = 0; j < n; ++j)                     //开始寻找最小的d[u]
              {
                     if (vis[j] == false && d[j] < MIN)
                     {
                           u = j;
                           MIN = d[j];
                     }
              }
              //找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
              if (u == -1)
                     return;
              vis[u] = true;                                  //标记u已被访问
              for (int v = 0; v < n; ++v)
              {
                     //遍历所有顶点，如果v未被访问&&u能够到达v&&以u为中介点可以使d[v]更优
                     if (vis[v] == false && d[u] + G[u][v] < d[v])
                           d[v] = d[u] + G[u][v];             //更新d[v]
              }
       }
}
```

邻接表版：
```C++
const int INF = 1000000000;
 
struct Node
{
       int v;         //边的目标顶点
       int dis;       //dis为边权
       Node(int x, int y) :v(x), dis(y) {}
};
 
void Dijkstra(int n, int s, vector<vector<Node>> Adj, vector<bool> vis, vector<int>& d)
{
       /*
       param
       n：      顶点个数
       s：      起点
       Adj：    图的邻接表
       vis：    标记顶点是否被访问
       d：      存储起点s到其他顶点的最短距离
       */
       fill(d.begin(), d.end(), INF);
       d[s] = 0;                                             //起点s到达自身的的距离为0
       for (int i = 0; i < n; ++i)
       {
              int u = -1;                                    //找到d[u]中最小的u
              int MIN = INF;                                 //找到最小的d[u]
              for (int j = 0; j < n; ++j)                    //寻找最小的d[u]
              {
                     if (vis[j] == false && d[j] < MIN)
                     {
                           u = j;
                           MIN = d[j];
                     }
              }
              //找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
              if (u == -1)
                     return;
              vis[u] = true;                                //标记u被访问
              for (int j = 0; j < Adj[u].size(); ++j)
              {
                     int v = Adj[u][j].v;                   //通过邻接表获取u能直接到达的v
                     if (vis[v] == false && d[v] > d[u] + Adj[u][j].dis)     
                           d[v] = d[u] + Adj[u][j].dis;       //优化d[u]
              }
       }
}
```