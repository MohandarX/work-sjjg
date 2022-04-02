//顺序栈
#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef char ElemType;
typedef struct
{
    ElemType* a;
    int top;  //top指向真实的栈顶元所在下标，初始值为-1
}SqStack;
bool Init(SqStack& st);//栈的初始化，为动态数组分配一个预定义大小的空间,top初值为0,如果申请存储空间失败返回false，否则返回true；
bool Empty(SqStack st);//判断栈是否为空，如果为空返回true，否则返回false
bool Read(SqStack st, ElemType& x);//取栈顶元，若栈为空，返回false ；否则返回true，并将栈顶元赋值到x
bool Push(SqStack& st, ElemType x);//入栈操作，若栈已满，入栈失败，返回false ；否则将x入栈，并返回true
bool Pop(SqStack& st, ElemType& x);//出栈操作，若栈为空，出栈失败，返回false；否则将栈顶元出栈，并返回true,并将栈顶元赋值到x。
void Destroy(SqStack& st);// 销毁栈
void Dto16(unsigned int M);
int main()
{
    unsigned int M;
    cin >> M;
    cout << "the result is :  ";
    Dto16(M);
    return 0;
}
bool Init(SqStack& st)
{
    st.a = new ElemType[MAXSIZE];
    if (st.a == NULL) return false;
    st.top = -1;
    return true;
}
bool Empty(SqStack st)
{
    if (st.top == -1) return true;
    return false;
}
void Destroy(SqStack& st)  //
{
    delete[]st.a;  //释放动态获取的空间
    st.top = -1;
}
bool Read(SqStack st, ElemType& x)
{
    if (st.top == -1)
    {
        return false;
    }
    else
    {
        x = st.a[st.top];
        return true;
    }
}
void Dto16(unsigned int M)
{
    SqStack st;
    Init(st);
    do
    {
        ElemType T;
        if (M % 16 > 9)
        {
            T = (char)(M % 16 + 55);
        }
        else
        {
            T = (char)(M % 16 + 48);
        }
        Push(st, T);
        M /= 16;
    } while (M != 0);
    ElemType x;
    while (Pop(st,x))
    {
        cout << x << ' ' << ' ';
    }
}
bool Push(SqStack& st, ElemType x)
{
    if (st.top >= 99)
    {
        return false;
    }
    st.a[st.top + 1] = x;
    st.top++;
    return true;
}
bool Pop(SqStack& st, ElemType& x)
{
    if (Empty(st))
    {
        return false;
    }
    x = st.a[st.top];
    st.top--;
    return true;
}
