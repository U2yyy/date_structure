//
// Created by Programmer on 2022/6/12.
//
#include <stdio.h>
#include <string.h>
#define MaxVertex 10
//创建数组存储是否访问
int visited[MaxVertex];
//创造邻接点结构体
struct EdgeNode{
    //记录这个结点的位置
    int position;
    //指向后续结点的指针
    struct EdgeNode *next;
};
//创造顶点结构体
struct Vertex{
    //顶点名字
    char name[99];
    //指向第一个邻接点的指针
    struct EdgeNode *first;
};
//创造整个邻接表图的结构体
struct LinkGraph{
    //定义每个顶点的名字
    struct Vertex vertex[MaxVertex];
    //顶点个数
    int VertexNum;
    //边条数
    int EdgeNum;
};
int findLocation(struct LinkGraph *graph,char v[99]){
    int temp = -1;
    for(int i=0;i<graph->VertexNum;i++){
        if(strcmp(graph->vertex[i].name,v) == 0)
            temp = i;
        break;
    }
    return temp;//若返回值为-1说明没找到
}
void DFS(struct LinkGraph *myGraph,int i){
    visited[i] = 1;
    printf("%s",myGraph->vertex[i].name);
    struct EdgeNode *p = myGraph->vertex[i].first;
    while(p){
        if(visited[p->position]==0)
            DFS(myGraph,p->position);
        p = p->next;
    }
}
void DFSreverse(struct LinkGraph *myGraph){
    for(int i=0;i<myGraph->VertexNum;i++){
        visited[i] = 0;
    }
    for(int i=0;i<myGraph->VertexNum;i++){
        if(visited[i]==0)
            DFS(myGraph,i);
    }
}
void test1(){
    struct LinkGraph myGraph;
    printf("请输入顶点（vertex）的数量和边（edge）的数量：\n");
    scanf("%d %d",&myGraph.VertexNum,&myGraph.EdgeNum);
    printf("请依次输入每个顶点的名称\n");
    for(int i=0;i<myGraph.VertexNum;i++){
        scanf("%s",myGraph.vertex[i].name);
        myGraph.vertex[i].first = NULL;
    }
    for(int i=0;i<myGraph.EdgeNum;i++) {
        char v1[99],v2[99];
        printf("请输入互为邻接点的两个顶点\n");
        scanf("%s%s",v1,v2);
        int temp1 = findLocation(&myGraph,v1);
        int temp2 = findLocation(&myGraph,v2);
        if(temp1!=-1&&temp2!=-1) {
            //新建结点
            struct EdgeNode *newEdge;
            newEdge->position = temp2;
            //采用头插法，效率更高
            newEdge->next = myGraph.vertex[temp1].first;
            myGraph.vertex[temp1].first = newEdge;
        }
    }
    DFSreverse(&myGraph);
}
int main(){
    test1();
    return 0;
}