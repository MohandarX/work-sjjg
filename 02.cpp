//Ë³Ðò±í
#include<iostream>
using namespace std;
#define MAXSIZE 5
#define ERROR -1
typedef int ElementType;
typedef struct LNode 
{
    ElementType* Data;
    int Last;
}SqList;
bool MakeEmpty(SqList& L)
{
    L.Data = NULL;
    L.Data = new ElementType [MAXSIZE];
    if (!L.Data)
    {
        return false;
    }
    L.Last = -1;
    return true;
}
int Find(SqList& L, ElementType X)
{
    int i = 0;
    for (i = 0; i <= L.Last; i++)
    {
        if (L.Data[i] == X)
        {
            return i;
        }
    }
    return ERROR;
}
bool Insert(SqList& L, ElementType X, int P)
{
    if (L.Last + 1 >= MAXSIZE)
    {
        cout << "FULL";
        return false;
    }
    if (0 <= P && P <= L.Last + 1)
    {
        int i = 0;
        for (i = L.Last; i >= P; i--)
        {
            L.Data[i + 1] = L.Data[i];
        }
        L.Data[i + 1] = X;
        ++L.Last;
        return true;
    }
    else
    {
        cout << "ILLEGAL POSITION";
        return false;
    }
}
bool Delete(SqList& L, int P)
{
    if (0 <= P && P <= L.Last)
    {
        int i = 0;
        for (i = P; i < L.Last; i++)
        {
            L.Data[i] = L.Data[i + 1];
        }
        --L.Last;
        return true;
    }
    else
    {
        cout << "POSITION" << " " << P << " " << "EMPTY";
        return false;
    }
}
int main()
{
    SqList L;
    ElementType X;
    int P;
    int N;
    if (MakeEmpty(L) == false) return 0;
    cin >> N;
    while (N--)
    {
        cin >> X;
        if (Insert(L, X, 0) == false)
            cout << " Insertion Error: " << X << " is not in." << endl;
    }
    cin >> N;
    while (N--)
    {
        cin >> X;
        P = Find(L, X);
        if (P == ERROR)
            cout << "Finding Error: " << X << " is not in." << endl;
        else
            cout << X << " is at position " << P << "." << endl;
    }
    cin >> N;
    while (N--)
    {
        cin >> P;
        if (Delete(L, P) == false)
            cout << " Deletion Error." << endl;
        if (Insert(L, 0, P) == false)
            cout << " Insertion Error: 0 is not in." << endl;
    }
    return 0;
}
