//二叉排序树
#include<stdio.h>  
#include<stdlib.h>  

typedef struct BiTNode
{
    int key;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int SearchBST(BiTree T, int key, BiTree f, BiTree p)//查找
{
    if (!T)  { p = f; return 0; }
    else if (key == T->key) { p = T; return 1; }
    else if (key<T->key) SearchBST(T->lchild, key, T, p);
    else SearchBST(T->rchild, key, T, p);
}

int InsertBST(BiTree T, int key)//插入
{
    if (!T)
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        T->key = key;
        T->lchild = (T)->rchild = NULL;
    }
    if (key == T->key) return 0;
    if (key>T->key) InsertBST(T->rchild, key);
    else InsertBST(T->lchild, key);
}

void InorderTraverse(BiTree T)//中序遍历
{
    if (T)
    {
        InorderTraverse(T->lchild);
        printf("%d ", T->key);
        InorderTraverse(T->rchild);
    }
}

void Delete(BiTree p) //删除
{
    BiTree q, s;
    if (!p->lchild &&!p->rchild) //p为叶子节点 
        p = NULL;
    else if (!p->lchild) //左子树为空，重接右子树
    {
        q = p;
        p = p->rchild;
        free(q);
    }
    else if (!p->rchild) //右子树为空，重接左子树
    {
        q = p;
        p = p->lchild;
        free(q);
    }
    else  //左右子树均不为空  
    {
        q = p;
        s = p->lchild;
        while (s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        p->key = s->key;
        if (q != p)
            q->rchild = s->lchild;
        else
            q->lchild = s->lchild;
        free(s);
    }
}

int DeleteBST(BiTree T, int key)//删除
{
    if (!T) return 0;
    else
    {
        if (key == T->key) Delete(T);
        else if (key<T->key)  DeleteBST(T->lchild, key);
        else  DeleteBST(T->rchild, key);
    }
}

int main()
{
    int e, n;
    BiTree T = NULL, f, p;
    printf("输入长度：");
    scanf("%d", &n);
    printf("输入元素：");
    while (n--)
    {
        scanf("%d", &e);
        InsertBST(T, e);
    }
    printf("中序遍历：");
    InorderTraverse(T);
    printf("\n");
    while (1)
    {
        printf("输入要查找元素：");
        scanf("%d", &e);
        if (SearchBST(T, e, f, p)) printf("找到了\n");
        else printf("没找到\n");
        printf("输入要插入元素：");
        scanf("%d", &e);
        InsertBST(T, e);
        printf("中序遍历：");
        InorderTraverse(T);
        printf("\n");
        printf("输入要删除元素：");
        scanf("%d", &e);
        DeleteBST(T, e);
        printf("中序遍历：");
        InorderTraverse(T);
        printf("\n");
    }
}
