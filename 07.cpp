#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct node /*二叉树结构定义*/
{
    char data;
    struct node* lchild, * rchild;
}binnode;
typedef binnode* bintree;
void CreateBinTree(bintree& T);/*按前序遍历顺序建立一棵二叉树,通过引用类型返回树根地址     */
void PreOrder(bintree T);    /* t为指向树根结点的指针,树的前序遍历*/
void InOrder(bintree T); /* t为指向树根结点的指针,树的中序遍历*/
void PostOrder(bintree T); /* t为指向树根结点的指针,树的后序遍历*/
int main()
{
    bintree T;
    CreateBinTree(T);   /*建立二叉树T*/
    printf("\nthe PreOrder is:");
    PreOrder(T);
    printf("\nthe InOrder is:");
    InOrder(T);
    printf("\nthe PostOrder is:");
    PostOrder(T);
    return 0;
}
void CreateBinTree(bintree& T)
{
    char ch;
    cin >> ch;
    if (ch == '#')  T = NULL;
    else
    {
        T = new binnode;
        T->data = ch;
        CreateBinTree(T->lchild);
        CreateBinTree(T->rchild);
    }
}
void PreOrder(bintree T)
{
    if (T)
    {
        cout << T->data;
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
void InOrder(bintree T)
{
    if (T)
    {
        InOrder(T->lchild);
        cout << T->data;
        InOrder(T->rchild);
    }
}
void PostOrder(bintree T)
{
    if (T)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        cout << T->data;
    }
}
