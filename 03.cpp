//单链表
#include<iostream>
using namespace std;
typedef int datatype;
typedef struct ListNode 
{
    datatype data;
    struct ListNode* next;
}LNode, * LinkList;
void CreateList(LinkList& L); /*单链表创建*/
void Reverse(LinkList& L);  /*其中L是用户传入的带头节点单链表的头指针,L是引用类型；函数Reverse将链表L逆置。*/
void PrintList(LinkList L); /*单链表输出*/
int main()
{
    LinkList L;
    CreateList(L); //创建带头节点的单链表
    Reverse(L);
    PrintList(L);
    return 0;
}
void CreateList(LinkList& L)
{
    LNode* r, * s;
    datatype x;
    L = r = new LNode;  //生成新节点作为头节点，用头指针L指向。
    cin >> x;
    while (x != -1)
    {
        s = new LNode;
        s->data = x;
        r->next = s;
        r = s;
        cin >> x;
    }
    r->next = NULL;
}
void PrintList(LinkList L)
{

    LNode* p = L->next;
    if (p == NULL) cout << "Empty";
    else

        while (p) 
        {
            cout << p->data << " ";
            p = p->next;
        }
    cout << endl;
}
void Reverse(LinkList& L)
{
    LNode* p = L->next;
    L->next = NULL;
    while (p != NULL) 
    {
        LNode* tmp;
        tmp = p->next;
        p->next = L->next;
        L->next = p;
        p = tmp;
    }
}
