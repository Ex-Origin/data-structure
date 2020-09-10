/* 
 * 和 严蔚敏 数据结构 书上代码原理一致
 ***/
#include <stdio.h>
#include <stdlib.h>
#define N 7 //顶点个数

//邻接表的结构体
typedef struct Node
{
    int adjvex;
    struct Node *next;
} edgenode;

typedef struct
{
    char vertex;
    int id;
    edgenode *link;
} vexnode;

//进行拓扑排序
void TopoSort_AdjTable(vexnode ga[N])
{
    int i, j, k, m = 0, top = -1;
    edgenode *p;
    for (i = 0; i < N; i++) //将入度为0的顶点入栈
        if (ga[i].id == 0)
        {
            ga[i].id = top;
            top = i;
        }
    while (top != -1) //栈不为空
    {
        j = top;
        top = ga[top].id; //出栈
        printf("%c", ga[j].vertex);
        m++;
        p = ga[j].link;
        while (p) //删除该节点的所有出边
        {
            k = p->adjvex - 1;
            ga[k].id--;
            if (ga[k].id == 0) //将入度为0的顶点入栈
            {
                ga[k].id = top;
                top = k;
            }
            p = p->next;
        }
    }
    if (m < N) //当输出的顶点数小于N时，说明有环存在
        printf("该图存在环！");
}

void main()
{
    vexnode ga[N];
    char vertex[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int ID[N] = {0, 1, 2, 0, 1, 1, 3};
    for (int i = 0; i < N; i++)
    {
        ga[i].vertex = vertex[i];
        ga[i].id = ID[i];
    } //初始化顶点表
    edgenode *s;

    //初始化边表
    s = (edgenode *)malloc(sizeof(edgenode));
    s->adjvex = 2;
    ga[0].link = s;
    s = (edgenode *)malloc(sizeof(edgenode));
    s->adjvex = 3;
    ga[0].link->next = s;
    s->next = NULL;

    s = (edgenode *)malloc(sizeof(edgenode));
    s->adjvex = 6;
    ga[1].link = s;
    s = (edgenode *)malloc(sizeof(edgenode));
    s->adjvex = 7;
    ga[1].link->next = s;
    s->next = NULL;

    s = (edgenode *)malloc(sizeof(edgenode));
    s->adjvex = 7;
    ga[2].link = s;
    s->next = NULL;

    s = (edgenode *)malloc(sizeof(edgenode));
    s->adjvex = 3;
    ga[3].link = s;
    s = (edgenode *)malloc(sizeof(edgenode));
    s->adjvex = 5;
    ga[3].link->next = s;
    s->next = NULL;

    s = (edgenode *)malloc(sizeof(edgenode));
    s->adjvex = 7;
    ga[4].link = s;
    s->next = NULL;

    ga[5].link = NULL;
    ga[6].link = NULL;
    //初始化边表结束
    TopoSort_AdjTable(ga); //进行拓扑排序
    printf("\n");
}
