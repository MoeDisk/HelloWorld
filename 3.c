#include <iostream>

using namespace std;

//���ʱ�־������,Ϊ1��ʾ���ʹ���Ϊ0��ʾδ������
int visted[100];
//�߱���
typedef struct EdgeNode {
    //�����Ӧ���±�
    int adjvex;
    //ָ����һ���ڽӵ�
    struct EdgeNode *next;
} edgeNode;

//�������
typedef struct VertexNode {
    //��������
    char data;
    //�߱�ͷָ��
    edgeNode *firstedge;
} VertexNode, AdjList[100];

//����
typedef struct {
    AdjList adjList;
    //�������ͱ���
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
    //���붥�����ͱ���
    cin >> G->numVertexes >> G->numEdges;
    //���붥����Ϣ�����������
    for (i = 0; i < G->numVertexes; i++)
    {
        //���붥����Ϣ
        cin >> G->adjList[i].data;
        //���߱���Ϊ�ձ�
        G->adjList[i].firstedge = NULL;
    }
    //�����߱�ͷ�巨��
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
            //�ݹ����
            DFS(G, p->adjvex);
        }
        p = p->next;
    }

}

void AdjacencyList::DFSTraverse(GraphAdjList *G) {
    //��ʼ�����ж��㶼û�з��ʹ�
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