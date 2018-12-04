#ifndef DEL_H
#define DEL_H
int delnode(int node, int **w); //从网络拓扑中删除一个路由器结点并存入文件中去
void deledge(int node, int **w); //从网络拓扑中删除某条边并将其存入到文件中去
#endif // !DEL_H
