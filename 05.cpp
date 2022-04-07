//循环队列
#include <iostream>
#include <cstring>
using namespace std;
typedef int ElemType;
typedef enum { addq, delq, End } Operation;
typedef struct QNode
{
    ElemType* Data;  /* 存储元素的数组   */
    int Front;     /* 队列的头 */
    int Rear;          /* 队列的尾   */
    int MaxSize;        /* 队列最大容量     */
} Queue;
bool CreateQueue(Queue& Q, int MaxSize); //创建初始队列
bool AddQ(Queue& Q, ElemType X);//实现入队操作，如果队列已满，AddQ函数必须输出“Queue Full”并且返回false；否则返回true
bool DeleteQ(Queue& Q, ElemType& X);  //实现出队操作，如果队列是空的，则DeleteQ函数必须输出“Queue Empty”，并且返回false,否则将队首的值赋给X，并返回true。
Operation GetOp(); //读取操作指令
int main()
{
    ElemType X;
    Queue Q;
    int N, done = 0;
    cin >> N;
    CreateQueue(Q, N);
    while (!done)
    {
        switch (GetOp())
        {
        case addq:
            cin >> X;
            if (!AddQ(Q, X)) cout << "Queue is Full" << endl;
            break;
        case delq:
            if (DeleteQ(Q, X)) cout << X << " is out" << endl;
            break;
        case End:
            while (Q.Front != Q.Rear)
            {
                DeleteQ(Q, X);
                cout << X << " ";
            }
            done = 1;
            break;
        }
    }
    return 0;
}
Operation GetOp()
{
    char op[5];
    cin >> op;

    if (strcmp(op, "Add") == 0) return addq;

    if (strcmp(op, "Del") == 0) return delq;

    if (strcmp(op, "End") == 0) return End;

}
bool CreateQueue(Queue& Q, int MaxSize)
{
    /* 注意：为区分空队列和满队列，需要多开辟一个空间 */
    MaxSize++;
    Q.Data = new ElemType[MaxSize];
    if (Q.Data == NULL) return false;
    Q.Front = Q.Rear = 0;
    Q.MaxSize = MaxSize;
    return true;
}
bool AddQ(Queue& Q, ElemType X)
{
    if ((Q.Rear + 1) % Q.MaxSize == Q.Front)
    {
        cout << "Queue Full" << endl;
        return false;
    }
    Q.Data[Q.Rear] = X;
    Q.Rear = (Q.Rear + 1) % Q.MaxSize;
    return true;
}
bool DeleteQ(Queue& Q, ElemType& X)
{
    if (Q.Rear == Q.Front)
    {
        cout << "Queue Empty" << endl;
        return false;
    }
    X = Q.Data[Q.Front];
    Q.Front = (Q.Front + 1) % Q.MaxSize;
    return true;
}
