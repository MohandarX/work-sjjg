#include<iostream>
using namespace std;
typedef struct BiThrNode
{
    char data;
    struct BiThrNode* lchild, * rchild;
    int LTag = 1, RTag = 1;
} BiThrNode, * BiThrTree;
BiThrNode* pre;
void CreateBinTree(BiThrTree& T);
void InThreading(BiThrTree p);  // 以结点P为根的子树中序线索化
void InOrderTraverse_Thr(BiThrTree T); // 中序遍历二叉线索树T的非递归算法，对每个数据元素直接输出
int main()
{
    BiThrTree tree;
    pre = new BiThrNode;
    CreateBinTree(tree);
    InThreading(tree);
    InOrderTraverse_Thr(tree);
    return 0;
}
void InThreading(BiThrTree p)
{
    if (p)
    {
        InThreading(p->lchild);
        if (!p->lchild)
        {
            p->LTag = 1;
            p->lchild = pre;
        }
        else p->LTag = 0;
        if (!pre->rchild)
        {
            pre->RTag = 1;
            pre->rchild = p;
        }
        else pre->RTag = 0;
        pre = p;
        InThreading(p->rchild);
    }
    pre->RTag = 1;
}
void CreateBinTree(BiThrTree& T)
{
    char ch;
    cin >> ch  ;
    if (ch == '#')  T = NULL;
    else
    {
        T = new BiThrNode;
        T->data = ch;
        CreateBinTree(T->lchild);
        CreateBinTree(T->rchild);
    }
}

void InOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree p = T;
    while (p)
    {
        while (!p->LTag)
        {
            p = p->lchild;
        }
        cout << p->data << ' ' << p->LTag << ' ' << p->RTag << endl;
        while (p->RTag&& p)
        {
            p = p->rchild;
            cout << p->data << ' ' << p->LTag << ' ' << p->RTag << endl;
        }
        p = p->rchild;
    }
}
