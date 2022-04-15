# Deque

![deque](https://thispointer.com//wp-content/uploads/2015/07/deque.png)

# Tree

**Prefix Tree**

Problems: 208



# Graph

**Interface**

```c++
# edge
e();
exist(v, u);
insert(v, u);
remove(v, u);
status(v, u);
edge(v, u);
weight(v, u);
# vertex
n();
insert(v);
remove(v);
inDegree(v); outDegree(v);
firstNbr(v);
nextNbr(v, u);
status(v);
dTime(v); fTime(v);
parent(v);
priority(v);
# state
enum VState {UNDISCOVERED, DISCOVERED, VISITED};
enum EState {UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD};
template <typename Tv, typename Te>
class Graph {
private:
    void reset();
    // O(n + e) for adjacent list
    void BFS(int, int&);
    void DFS(int, int&);
    void BCC(int, int&, Stack<int>&); // 基于DFS的双连通分量分解算法
    bool TSort(int, int&, Stack<Tv>*); // 基于DFS的拓扑排序算法
public:
    void bfs(int);
    void dfs(int);
    void bcc(int);
    Stack<Tv>* tSort(int);
    void prim(itn);
    void dijkstra(int);
    template <typename PU> void pfs(int, PU);
}
```

**Topological sorting**

Iteratively remove the point that have 0 indegree.
207 210