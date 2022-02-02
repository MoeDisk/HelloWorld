#include <iostream>

using namespace std;

//访问标志的数组,为1表示访问过，为0表示未被访问
int visted[100];
//边表结点
typedef struct EdgeNode {
    //顶点对应的下标
    int adjvex;
    //指向下一个邻接点
    struct EdgeNode *next;
} edgeNode;

//顶点表结点
typedef struct VertexNode {
    //顶点数据
    char data;
    //边表头指针
    edgeNode *firstedge;
} VertexNode, AdjList[100];

//集合
typedef struct {
    AdjList adjList;
    //顶点数和边数
    int numVertexes, numEdges;
} GraphAdjList;

class AdjacencyList {
public:

    void CreateALGraph(GraphAdjList *G);

    void ShowALGraph(GraphAdjList *G);

    void DFS(GraphAdjList *G, int i);

    void DFSTraverse(GraphAdjList *G);

    void Test();


};

void AdjacencyList::CreateALGraph(GraphAdjList *G) {
    int i, j, k;
    edgeNode *e;
    cout << "Enter vertex and edges" << endl;
    //输入顶点数和边数
    cin >> G->numVertexes >> G->numEdges;
    //读入顶点信息，建立顶点表
    for (i = 0; i < G->numVertexes; i++)
    {
        //输入顶点信息
        cin >> G->adjList[i].data;
        //将边表置为空表
        G->adjList[i].firstedge = NULL;
    }
    //建立边表（头插法）
    for (k = 0; k < G->numEdges; k++)
    {
        cout << "Enter the edge(vi,vj)Vertex serial number on" << endl;
        cin >> i >> j;
        e = new EdgeNode;
        e->adjvex = j;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;

        e = new EdgeNode;

        e->adjvex = i;
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }
}

void AdjacencyList::Test() {
    cout << "ALL IS OK." << endl;
}

void AdjacencyList::ShowALGraph(GraphAdjList *G) {
    for (int i = 0; i < G->numVertexes; i++)
    {
        cout << "VERTEX" << i << ": " << G->adjList[i].data << "--firstedge--";
        edgeNode *p = new edgeNode;
        p = G->adjList[i].firstedge;
        while (p)
        {
            cout << p->adjvex << "--Next--";
            p = p->next;
        }
        cout << "--NULL" << endl;
    }

}

void AdjacencyList::DFS(GraphAdjList *G, int i) {
    EdgeNode *p;
    visted[i] = 1;
    cout << G->adjList[i].data << "--";
    p = G->adjList[i].firstedge;
    while (p)
    {
        if (!visted[p->adjvex])
        {
            //递归访问
            DFS(G, p->adjvex);
        }
        p = p->next;
    }

}

void AdjacencyList::DFSTraverse(GraphAdjList *G) {
    //初始化所有顶点都没有访问过
    cout<<"The depth-first traversal result is: "<<endl;
    for (int i = 0; i < G->numVertexes; i++)
    {
        visted[i] = 0;
    }
    for (int i = 0; i < G->numVertexes; i++)
    {
        if (visted[i] == 0)
        {
            DFS(G, i);
        }
    }
}

int main() {

    AdjacencyList adjacencyList;
    GraphAdjList *GA = new GraphAdjList;
    adjacencyList.Test();
    adjacencyList.CreateALGraph(GA);
    adjacencyList.ShowALGraph(GA);
    adjacencyList.DFSTraverse(GA);
    return 0;
}